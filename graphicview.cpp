#include "graphicview.h"
#include <QKeyEvent>
#include <QDebug>

GraphicsView::GraphicsView(QWidget* parent) : QGraphicsView(parent)
{
    setFocusPolicy(Qt::StrongFocus);
}

void GraphicsView::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Return)
    {
        qDebug()<<"hola";
    }
    else
    {
        QGraphicsView::keyPressEvent(event);
    }
}
