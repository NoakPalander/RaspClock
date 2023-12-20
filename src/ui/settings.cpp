#include "settings.hpp"
#include "ui_settings.h"

namespace rasp {
    Settings::Settings(QWidget *parent): QWidget(parent), ui_(new Ui::settings) {
        ui_->setupUi(this);
    }

    Settings::~Settings() {
        delete ui_;
    }
}