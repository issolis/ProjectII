#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <blocklist.h>
#include <pathfindinglist.h>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <listid.h>
#include <localserver.h>

class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPushButton *b_LevelI = new QPushButton("Level I");
    QGraphicsProxyWidget *L1;
    blockList list;
    pathFindingList listMatL1;
    QGraphicsPixmapItem *enemy1;
    QGraphicsPixmapItem *enemy2;
    QGraphicsPixmapItem *pacman;
    void bL1_Clicked();
    int adapPosX(int id);
    int adapPosY(int id);
    void MoveFirstEnemy();
    void MoveSecondEnemy();
    void defineRouteFirstEnemy();
    void defineRouteSecondEnemy();
    int *vecMove;
    int randNumber();
    void movePlayer();
    void colocatePoints();
    QVariant direcction=1;
    bool noPutIt(int level, int ID);
    blockList points;
    listID poinstGotten;
    void checkPoints();
    void server();
    LocalServer *Server;
    int determinateDirecction(QString comas);


protected:
    void keyPressEvent(QKeyEvent *event) override;


};

#endif // CUSTOMWIDGET_H
