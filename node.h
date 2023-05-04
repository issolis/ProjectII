#ifndef NODE_H
#define NODE_H
#include "pathfindingnode.h"

class node
{
public:
    node(pathFindingNode *id);
    node *next=nullptr;
    pathFindingNode* id;
};

#endif // NODE_H
