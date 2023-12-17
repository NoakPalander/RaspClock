#ifndef RASP_CLOCK_HPP
#define RASP_CLOCK_HPP

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

        void update(std::stop_token token);

    signals:
        void tick(QString string);

    private slots:
        void on_tick(QString const& string) const;

    private:
        Ui::clock* ui_;
        std::jthread thread_;
    };
}

#endif // !RASP_CLOCK_HPP