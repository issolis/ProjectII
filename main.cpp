#include "widget.h"

#include <QApplication>
#include <pathfindinglist.h>
#include <graphicview.h>
#include <windowgame.h>
#include <blocklist.h>
#include <QTimer>
#include <localserver.h>
#include <QThread>
#include <QRandomGenerator>
class serverManager{
public:

    LocalServer *server;
    serverManager(){
        server=new LocalServer();
        server->listen(QHostAddress::Any, 1234);
    }

    void waitConnection(){
        while (true) {
            if (server->waitForNewConnection()) {
                qDebug()<<("Connected");
                break;
            }
            QThread::msleep(0.001);
        }

    }
};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    serverManager *manager= new serverManager();
    //manager->waitConnection();
    widget w;
    w.show();

    return a.exec();

}



