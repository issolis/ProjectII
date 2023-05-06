#include "widget.h"

#include <QApplication>
#include <pathfindinglist.h>
#include <graphicview.h>
#include <windowgame.h>
#include <blocklist.h>
#include <QTimer>;

#include <QRandomGenerator>
int posXL [54]={-120,-100,-80 ,-60 , -40,-20 ,0   ,-60 ,-60,-60,-60,-120,-100,-80 ,-60 , -40,-20 ,0,40,40,40,40,40,40,60,80,100,120,120,120,120,120,120,-40,-40,-40,-40,-40,-20,0,-20,0,40,40,40,40,40,60,80,60,80,60,80};
int posYL [54]={-120,-120,-120,-120,-120,-120,-120,-100,-80,-60,-40,-20 ,-20 ,-20 ,-20 ,-20 ,-20 ,-20,-120,-100,-80,-60,-40,-20,-100,-80,-100,-120,-100,-80,-60,-40,-20,20,40,60,80,100, 20,20,100,100,20,40,60,80,100,20,20,60,60,100,100};

int randNumber(){
    int i=0; bool again=false;
    while(true){
        again=false;
        int rand=QRandomGenerator::global()->bounded(1, 331);
        while(i!=53){
            if((220+posXL[i])/20+(140+posYL[i])/20*22+1==rand){
                again=true;
                break;
            } i++;
        }


        if(!again)
            return rand;
    }

}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    pathFindingList l;

    l.buildMatrix(15,22 );

    int i=0;
    /*while(i!=54){
        int x=(220+posXL[i])/20+(140+posYL[i])/20*22+1;
        l.findNode(x)->closed=true;
        i++;
    }
     l.show();
    l.findRoute(12,76);
    l.findRoute(76,15);*/




    widget w;
    w.show();



    return a.exec();

}



