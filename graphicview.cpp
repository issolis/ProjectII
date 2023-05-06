#include "graphicview.h"
#include <QKeyEvent>
#include <QDebug>
#include <windowgame.h>

bool GameStarted=false;
GraphicsView::GraphicsView(QWidget* parent) : QGraphicsView(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    centerOn(mapToScene(viewport()->rect().center()));

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
void GraphicsView:: setScene(QGraphicsScene *scene) {
    QGraphicsView::setScene(scene);
}

