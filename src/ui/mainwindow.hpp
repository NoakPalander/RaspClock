#ifndef RASP_MAINWINDOW_HPP
#define RASP_MAINWINDOW_HPP

#include <QMainWindow>
#include <QKeyEvent>
#include <stack>

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
        void keyPressEvent(QKeyEvent* event) override;

        Ui::mainwindow* ui_;
        std::stack<QWidget*> pages_;
    };
}

#endif// !RASP_MAINWINDOW_HPP
