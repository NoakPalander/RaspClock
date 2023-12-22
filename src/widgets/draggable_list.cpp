#include "draggable_list.hpp"

#include <QApplication>
#include <QEvent>
#include <iostream>

namespace rasp {
    DraggableList::DraggableList(QWidget* parent) : QListWidget(parent) {}
}