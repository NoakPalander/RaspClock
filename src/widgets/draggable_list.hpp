#ifndef RASP_DRAGGABLE_LIST_HPP
#define RASP_DRAGGABLE_LIST_HPP

#include <QListWidget>
#include <QMouseEvent>

namespace rasp {
    class DraggableList : public QListWidget {
        Q_OBJECT
    public:
        explicit DraggableList(QWidget* parent = nullptr);
        ~DraggableList() override = default;
    };
}

#endif // !RASP_DRAGGABLE_LIST_HPP