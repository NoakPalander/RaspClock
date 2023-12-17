#ifndef RASP_MAINWINDOW_HPP
#define RASP_MAINWINDOW_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class mainwindow;
}
QT_END_NAMESPACE

namespace rasp {
    class MainWindow : public QMainWindow {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget* parent = nullptr);
        ~MainWindow() override;

    private:
        Ui::mainwindow* ui_;
    };
}

#endif// !RASP_MAINWINDOW_HPP
