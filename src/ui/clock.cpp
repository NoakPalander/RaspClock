#include "clock.hpp"
#include "ui_clock.h"

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <string>

namespace {
    auto current_time() {
        using namespace std::chrono;

        auto const now = system_clock::now();
        auto const tp = zoned_time{current_zone(), now}.get_local_time();
        auto const dp = floor<days>(tp);

        auto split = hh_mm_ss{floor<milliseconds>(tp - dp)};
        return std::pair{split, now};
    }

    template<typename Duration>
    std::string format(std::chrono::hh_mm_ss<Duration> time) {
        auto hours = static_cast<unsigned int>(time.hours().count());
        auto minutes = static_cast<unsigned int>(time.minutes().count());
        auto seconds = static_cast<unsigned int>(time.seconds().count());

        return std::format("{:02}:{:02}:{:02}", hours, minutes, seconds);
    }
}

namespace rasp {
    Clock::Clock(QWidget* parent) : QWidget(parent), ui_(new Ui::clock), thread_(&Clock::update, this) {
        ui_->setupUi(this);

        connect(this, &Clock::tick, this, &Clock::on_tick);
    }

    Clock::~Clock() {
        thread_.request_stop();
        delete ui_;
    }

    void Clock::update(std::stop_token const& token) {
        while (!token.stop_requested()) {
            using namespace std::chrono_literals;

            auto[now, time_point] = current_time();
            auto const next = time_point + 1s;

            auto const time = QString::fromStdString(format(now));
            emit tick(time);

            std::this_thread::sleep_until(next);
        }
    }

    void Clock::on_tick(QString const& string) const {
        ui_->label->setText(string);
    }
}