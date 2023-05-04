#include "widget.h"

#include <QApplication>
#include <pathfindinglist.h>
#include <graphicview.h>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //Widget w;
    //w.show();
    GraphicsView view;
   // view.show();
    pathFindingList list;
    list.buildMatrix(10,10);
    list.show();
    list.findRoute(4,50 );
    return a.exec();

}
