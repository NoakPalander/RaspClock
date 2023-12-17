#include "mainwindow.hpp"

#include "clock.hpp"
#include "ui_mainwindow.h"

#include <iostream>

namespace rasp {
    MainWindow::MainWindow(QWidget* parent): QMainWindow(parent), ui_(new Ui::mainwindow) {
        ui_->setupUi(this);
        setFixedSize(size());

        auto const clock = new Clock(this);
        setCentralWidget(clock);
    }

    MainWindow::~MainWindow() {
        delete ui_;
    }
}
