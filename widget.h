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

    void bL1_Clicked();
    int adapPosX(int id);
    int adapPosY(int id);
    void auxMoveEnemies();
    void moveEnemies();
    int *vecMove;
    int randNumber();
protected:
    void keyPressEvent(QKeyEvent *event) override;



};

#endif // CUSTOMWIDGET_H
