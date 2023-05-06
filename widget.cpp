#include "widget.h"
#include <QDebug>
#include <QRandomGenerator>

int posXL1 [54]={-120,-100,-80 ,-60 , -40,-20 ,0   ,-60 ,-60,-60,-60,-120,-100,-80 ,-60 , -40,-20 ,0,40,40,40,40,40,40,60,80,100,120,120,120,120,120,120,-40,-40,-40,-40,-40,-20,0,-20,0,40,40,40,40,40,60,80,60,80,60,80};
int posYL1 [54]={-120,-120,-120,-120,-120,-120,-120,-100,-80,-60,-40,-20 ,-20 ,-20 ,-20 ,-20 ,-20 ,-20,-120,-100,-80,-60,-40,-20,-100,-80,-100,-120,-100,-80,-60,-40,-20,20,40,60,80,100, 20,20,100,100,20,40,60,80,100,20,20,60,60,100,100};

int posxE1=0;
int posYE1=0;
QVariant counter=0;
bool came=true;


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
        listMatL1.findNode((220+posXL1[i])/20+(140+posYL1[i])/20*22)->closed=true;
        aux=aux->next;
        i++;
    }
    listMatL1.show();
    scene->addItem(enemy1);
    auxMoveEnemies();
}
int widget::adapPosX(int id){
    return -220+id%22*20;
}
int widget::adapPosY(int id){
    return -140+(id-1)/22*20;
}
void widget::auxMoveEnemies(){
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        if(came==true){
            listMatL1.findRoute((220+enemy1->pos().x())/20+(140+enemy1->pos().y())/20*22 , randNumber());
            pathFindingNode *auxP=listMatL1.end;

            int *vec=new int [listMatL1.routeWeight];

            int i = listMatL1.routeWeight-1;

            while(auxP->parent!=nullptr){
                vec[i]=auxP->id;
                auxP=auxP->parent;
                i--;
            }
            counter=listMatL1.routeWeight;
            vecMove=vec;
            came=false;
            pathFindingList newList;
            newList.buildMatrix(15,22);
            listMatL1=newList;
            int j=0;
            blockNode *aux=list.head;
            while(aux!=nullptr){

                listMatL1.findNode((220+posXL1[j])/20+(140+posYL1[j])/20*22)->closed=true;
                aux=aux->next;
                j++;
            }

            listMatL1.show();


        }



    } );
    timer->start(200);
    moveEnemies();
}
void widget::moveEnemies(){
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        if(came==false && counter!=0){
            enemy1->setPos(adapPosX(*vecMove), adapPosY(*(vecMove)));
            vecMove++;
            qDebug()<<"1";
            counter=counter.toInt()-1;
            if(counter==0)
                came=true;

        }
    } );
    timer->start(300);
}
int widget::randNumber(){
    int i=0; bool again=false;
    while(true){
        again=false;
        int rand=QRandomGenerator::global()->bounded(1, 331);
        while(i!=53){
            if((220+posXL1[i])/20+(140+posYL1[i])/20*22==rand){
                again=true;
                break;
            } i++;
        }


          if(!again)
              return rand;
    }

}

