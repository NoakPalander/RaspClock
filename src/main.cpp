#include "ui/mainwindow.hpp"
#include <QApplication>

int main(int argc, char** argv) {
    [[maybe_unused]] QApplication app(argc, argv);
    rasp::MainWindow window;

#ifdef DEBUG
    window.show();
#else
    window.showFullScreen();
#endif

    return QApplication::exec();
}
