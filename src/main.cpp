#include "ui/mainwindow.hpp"
#include <QApplication>

int main(int argc, char** argv) {
    [[maybe_unused]] QApplication app(argc, argv);
    rasp::MainWindow window;
    window.showFullScreen();
    return QApplication::exec();
}
