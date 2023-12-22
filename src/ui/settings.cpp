#include "settings.hpp"
#include "ui_settings.h"
#include <QPropertyAnimation>
#include <filesystem>

namespace rasp {
    Settings::Settings(QWidget* parent): QWidget(parent), ui_(new Ui::settings) {
        ui_->setupUi(this);

        std::string const image = std::filesystem::current_path().parent_path().parent_path() / "resources/setting.png";
        ui_->settingsButton->setIcon(QIcon(QString::fromStdString(image)));

        auto* const zoomOut = new QPropertyAnimation(ui_->settingsButton, "iconSize", this);
        zoomOut->setDuration(75);
        zoomOut->setStartValue(ui_->settingsButton->iconSize());
        zoomOut->setEndValue(ui_->settingsButton->iconSize() * 0.9);

        connect(ui_->settingsButton, &QPushButton::pressed, this, [this, zoomOut] {
            if (zoomOut->state() != QAbstractAnimation::Running) {
                zoomOut->start();
            }
        });

        auto* const zoomIn = new QPropertyAnimation(ui_->settingsButton, "iconSize", this);
        zoomIn->setDuration(75);
        zoomIn->setStartValue(ui_->settingsButton->iconSize() * 0.9);
        zoomIn->setEndValue(ui_->settingsButton->iconSize());

        connect(ui_->settingsButton, &QPushButton::released, this, [this, zoomIn] {
            if (zoomIn->state() != QAbstractAnimation::Running) {
                zoomIn->start();
            }

            emit opened();
        });
    }

    Settings::~Settings() {
        delete ui_;
    }
}