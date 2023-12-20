#include "clock.hpp"
#include "ui_clock.h"

#include <fmt/format.h>
#include <chrono>
#include <iostream>
#include <string>

namespace {
    std::string format(std::chrono::time_point<std::chrono::system_clock> const& time) {
        time_t const x = std::chrono::system_clock::to_time_t(time);
        tm const* t = std::localtime(&x);

        return fmt::format("{:02}:{:02}:{:02}", t->tm_hour, t->tm_min, t->tm_sec);
    }
}

namespace rasp {
    Clock::Clock(QWidget* parent): QWidget(parent), ui_(new Ui::clock), thread_(&Clock::tick_update, this) {
        ui_->setupUi(this);

        connect(this, &Clock::tick, this, [this](QString const& string) {
            ui_->label->setText(string);
        });
    }

    Clock::~Clock() {
        stop_ = true;
        thread_.join();
        delete ui_;
    }

    // ReSharper disable once CppPassValueParameterByConstReference
    void Clock::tick_update() { // NOLINT(*-unnecessary-value-param)
        while (!stop_) {
            using namespace std::chrono_literals;

            auto const now = std::chrono::system_clock::now();
            auto const next = now + 1s;
            auto const time = QString::fromStdString(format(now));
            emit tick(time);

            std::this_thread::sleep_until(next);
        }
    }
}