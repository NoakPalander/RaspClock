#include "options.hpp"
#include "../widgets/draggable_list.hpp"
#include "ui_options.h"

#include <QPushButton>
#include <fmt/format.h>

namespace rasp {
    Options::Options(QWidget* parent): QWidget(parent), ui_(new Ui::options) {
        ui_->setupUi(this);

        auto* list = new DraggableList(this);
        ui_->verticalLayout->addWidget(list);

        for (int i = 0; i < 100; ++i) {
            auto* item = new QListWidgetItem(list);
            list->addItem(item);
            list->setItemWidget(item, new QPushButton(QString::fromStdString(fmt::format("Hello {}", i)), this));
        }
    }

    Options::~Options() {
        delete ui_;
    }
}