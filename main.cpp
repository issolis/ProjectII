#include "widget.h"

#include <QApplication>
#include <pathfindinglist.h>
#include <graphicview.h>
#include <windowgame.h>
#include <blocklist.h>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);




    widget w;
    w.show();
    pathFindingList list;
    list.buildMatrix(15,22);
    list.show();


    return a.exec();

}



