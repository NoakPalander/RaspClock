#ifndef RASP_OPTIONS_HPP
#define RASP_OPTIONS_HPP

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
    class options;
}
QT_END_NAMESPACE

namespace rasp {
    class Options : public QWidget {
        Q_OBJECT

    public:
        explicit Options(QWidget* parent = nullptr);
        ~Options() override;

    private:
        Ui::options* ui_;
    };
}

#endif// !RASP_OPTIONS_HPP