#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include "pathfindingnode.h"

class linkedList
{
public:
    linkedList();
    void insert(pathFindingNode* id);
    void deleteNode(pathFindingNode *Node);
    node *head=nullptr;

    int idFinal;

    pathFindingNode *min;

    void findMin();
    bool routeFinded=false;
};

#endif // LINKEDLIST_H
