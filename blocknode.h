#ifndef BLOCKNODE_H
#define BLOCKNODE_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class blockNode
{
public:
    blockNode();
    blockNode *next=nullptr;
    QGraphicsRectItem *item;
    QGraphicsPixmapItem *item1;
    int id=0;

};

#endif // BLOCKNODE_H
