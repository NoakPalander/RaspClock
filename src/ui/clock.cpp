#include "clock.hpp"
#include "ui_clock.h"

#include <fmt/format.h>
#include <chrono>
#include <iostream>
#include <string>

namespace {
    auto current_time() {
        return std::chrono::system_clock::now();
    }

    std::string format(std::chrono::time_point<std::chrono::system_clock> const& time) {
        auto const count = std::chrono::time_point_cast<std::chrono::seconds>(time).time_since_epoch().count();
        auto hours = std::chrono::duration_cast<std::chrono::hours>(std::chrono::seconds(count % 24)).count();
        auto minutes = std::chrono::duration_cast<std::chrono::minutes>(std::chrono::seconds(count % 3600)).count();
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::seconds(count % 60)).count();

        return fmt::format("{:02}:{:02}:{:02}", hours, minutes, seconds);
    }
}

namespace rasp {
    Clock::Clock(QWidget* parent) : QWidget(parent), ui_(new Ui::clock), thread_(&Clock::tick_update, this) {
        ui_->setupUi(this);

        connect(this, &Clock::tick, this, &Clock::on_tick);
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

            auto now = current_time();
            auto const next = now + 1s;

            auto const time = QString::fromStdString(format(now));
            emit tick(time);

            std::this_thread::sleep_until(next);
        }
    }

    void Clock::on_tick(QString const& string) const {
        ui_->label->setText(string);
    }
}