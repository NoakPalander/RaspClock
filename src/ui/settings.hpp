#ifndef RASP_SETTINGS_HPP
#define RASP_SETTINGS_HPP

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
    class settings;
}
QT_END_NAMESPACE

namespace rasp {
    class Settings : public QWidget {
        Q_OBJECT

    public:
        explicit Settings(QWidget* parent = nullptr);
        ~Settings() override;

    signals:
        void opened();

    private:
        Ui::settings* ui_;
    };
}

#endif // !RASP_SETTINGS_HPP
