#ifndef WINDOWGAME_H
#define WINDOWGAME_H

#include <QObject>
#include <graphicview.h>
#include <QTcpServer>
#include <QTcpSocket>

class WindowGame : public QTcpServer
{
public:
    WindowGame(QObject *parent = nullptr);
    GraphicsView view;
    void startView();
    QTcpSocket *socket;

protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // WINDOWGAME_H
