#include "windowgame.h"
#include <QDebug>
#include <QKeyEvent>

WindowGame::WindowGame(QObject *parent)
    : QTcpServer(parent)
{
   view.show();
   view.setFixedSize(1000,500);
   view.installEventFilter(this); // Instala el event filter en el view
}

void WindowGame::startView(){

}

bool WindowGame::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Space) { // Maneja la tecla presionada
            qDebug() << "Hola!";
            return true; // Se indica que el evento ha sido manejado
        } else {
            return false;
        }
    } else {
        // Si no es un evento de tecla presionada, se llama al event filter del padre
        return QObject::eventFilter(obj, event);
    }
}
