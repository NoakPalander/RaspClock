#ifndef RASP_CLOCK_HPP
#define RASP_CLOCK_HPP

#include "settings.hpp"


#include <QWidget>
#include <thread>

QT_BEGIN_NAMESPACE
    namespace Ui {
    class clock;
}
QT_END_NAMESPACE

namespace rasp {
    class Clock : public QWidget {
        Q_OBJECT

    public:
        explicit Clock(QWidget* parent = nullptr);
        ~Clock() override;

        void tick_update();

    signals:
        void tick(QString string);

    private:
        Ui::clock* ui_;
        std::thread thread_;
        std::atomic_bool stop_;
    };
}

#endif // !RASP_CLOCK_HPP