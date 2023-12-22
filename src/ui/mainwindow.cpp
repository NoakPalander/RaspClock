#include "mainwindow.hpp"

#include "clock.hpp"
#include "options.hpp"
#include "ui_mainwindow.h"

#include <fmt/format.h>
#include <iostream>

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

        connect(settings, &Settings::opened, this, [this] {
            ui_->centralwidget->setParent(nullptr);
            pages_.emplace(ui_->centralwidget);
            setCentralWidget(new Options(this));
        });
    }

    MainWindow::~MainWindow() {
        if (ui_->centralwidget->parent() == nullptr)
            delete ui_->centralwidget;

        delete ui_;
    }

    void MainWindow::keyPressEvent(QKeyEvent* event) {
        switch (event->key()) {
            case Qt::Key_Q: {
                close();
            } break;

            case Qt::Key_Backspace: {
                if (!pages_.empty()) {
                    setCentralWidget(pages_.top());
                    pages_.pop();
                }
            } break;

            default:
                break;
        }
    }
}
