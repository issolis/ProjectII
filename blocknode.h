#ifndef BLOCKNODE_H
#define BLOCKNODE_H
#include <QGraphicsRectItem>

class blockNode
{
public:
    blockNode();
    blockNode *next=nullptr;
    QGraphicsRectItem *item;
    int id=0;

};

#endif // BLOCKNODE_H
