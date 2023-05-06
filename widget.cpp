#include "widget.h"
#include <QDebug>
#include <QRandomGenerator>
#include <listid.h>

int posXL1 [54]={-120,-100,-80 ,-60 , -40,-20 ,0   ,-60 ,-60,-60,-60,-120,-100,-80 ,-60 , -40,-20 ,0,40,40,40,40,40,40,60,80,100,120,120,120,120,120,120,-40,-40,-40,-40,-40,-20,0,-20,0,40,40,40,40,40,60,80,60,80,60,80};
int posYL1 [54]={-120,-120,-120,-120,-120,-120,-120,-100,-80,-60,-40,-20 ,-20 ,-20 ,-20 ,-20 ,-20 ,-20,-120,-100,-80,-60,-40,-20,-100,-80,-100,-120,-100,-80,-60,-40,-20,20,40,60,80,100, 20,20,100,100,20,40,60,80,100,20,20,60,60,100,100};

int posxE1=0;
int posYE1=0;
int blocks=54;
QVariant counter=0;
bool came=true;
bool controler=true;
listID IDList;



widget::widget(QWidget *parent)
    : QWidget(parent)
{
    listMatL1.buildMatrix(14,22);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(-220,-140, 440, 280);
    QBrush brush(Qt::gray); // Se define un objeto QBrush con color gris
    scene->setBackgroundBrush(brush);
    view = new QGraphicsView(this);
    view->setScene(scene);
    view->setFixedSize(442, 282);
    L1 = scene->addWidget(b_LevelI);

    QPixmap myPixmap(":g1.png");
    enemy1 = new QGraphicsPixmapItem(myPixmap);

    QObject::connect(b_LevelI, &QPushButton::clicked, [&]{
        bL1_Clicked();
    });


}

void widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
    }
}
void widget::bL1_Clicked(){
    b_LevelI->hide();
    b_LevelI->setEnabled(false);


    list.insert(53);

    int i=0;
    blockNode *aux=list.head;
    while(aux!=nullptr){
        scene->addItem(aux->item);
        QBrush redBrush(Qt::blue);
        QPen pen(Qt::blue);
        aux->item->setBrush(redBrush);
        aux->item->setPen(pen);
        aux->item->setPos(posXL1[i], posYL1[i]);
        listMatL1.findNode (((220+posXL1[i])/20+(140+posYL1[i])/20*22)+1)->closed=true;
        aux=aux->next;
        i++;
    }

    scene->addItem(enemy1);
    auxMoveEnemies();
}

void widget:: defineRoute(){
    pathFindingList list;
    list.buildMatrix(14,22);

    int i=0;

    while(i!=54){
        list.findNode (((220+posXL1[i])/20+(140+posYL1[i])/20*22)+1)->closed=true;
        i++;
    }
    int conversionPos=((220+enemy1->pos().x())/20+(140+enemy1->pos().y())/20*22)+1;
    int x=randNumber();
    list.findRoute(conversionPos, x);
    qDebug()<<x;

    pathFindingNode *auxEnd= list.end;

    while (auxEnd!=nullptr) {
        IDList.insert(auxEnd->id);
        auxEnd=auxEnd->parent;
    }
    came=false;

    //IDList.show();

}

void widget::auxMoveEnemies(){
    int x; int y;
    QTimer *timer = new QTimer();

    QObject::connect(timer, &QTimer::timeout, [&]() {
        listID auxList=IDList;
        if(came){
            if(controler){
                pathFindingList list;
                list.buildMatrix(14,22);
                list.makeItTrue();

                int i=0;

                while(i!=54){
                    list.findNode (((220+posXL1[i])/20+(140+posYL1[i])/20*22)+1)->closed=true;
                    i++;
                }
                int conversionPos=((220+enemy1->pos().x())/20+(140+enemy1->pos().y())/20*22)+1;
                int x=randNumber();
                list.findRoute(conversionPos, x);
                qDebug()<<x;

                pathFindingNode *auxEnd= list.end;

                while (auxEnd!=nullptr) {
                    IDList.insert(auxEnd->id);
                    auxEnd=auxEnd->parent;
                }
                came=false;
                controler=false;
            }

        }
        else{
            qDebug()<< auxList.head->id;
            x=adapPosX( auxList.head->id);
            y=adapPosY(auxList.head->id);
            enemy1->setPos(x, y);
            IDList.deleteFirst();
            if(IDList.head==nullptr){
                came=true;
                controler=true;


            }
        }

    } );
    timer->start(200);
    //moveEnemies();
}




void widget::moveEnemies(){
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        defineRoute();

    } );
    timer->start(300);
}





int widget::randNumber(){
    int i=0; bool again=false;
    while(true){
        again=false;
        int rand=QRandomGenerator::global()->bounded(1, 301);
        while(i!=53){
            if((220+posXL1[i])/20+(140+posYL1[i])/20*22+1==rand){
                again=true;
                break;
            } i++;
        }

        if(!again)
            return rand;
    }

}





int widget::adapPosX(int id){
    return -220+id%22*20-20;
}
int widget::adapPosY(int id){
    return -140+(id-1)/22*20;
}



