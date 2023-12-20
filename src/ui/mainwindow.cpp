#include "mainwindow.hpp"

#include "clock.hpp"
#include "ui_mainwindow.h"

namespace rasp {
    MainWindow::MainWindow(QWidget* parent): QMainWindow(parent), ui_(new Ui::mainwindow) {
        ui_->setupUi(this);
        setFixedSize(size());

        auto const settings = new Settings();
        auto const buffer = new QWidget();
        buffer->setFixedWidth(settings->width());
        buffer->setFixedHeight(settings->height());

        auto const clock = new Clock();

        ui_->verticalLayout->addWidget(buffer, 0, Qt::AlignTop);
        ui_->verticalLayout->addWidget(clock, 0, Qt::AlignCenter);
        ui_->verticalLayout->addWidget(settings, 0, Qt::AlignBottom);
    }

    MainWindow::~MainWindow() {
        delete ui_;
    }
}
