#ifndef PATHFINDINGNODE_H
#define PATHFINDINGNODE_H


class pathFindingNode
{
public:
    pathFindingNode();

    pathFindingNode *right;
    pathFindingNode *left;
    pathFindingNode *up;
    pathFindingNode *down;

    pathFindingNode *parent;

    int idRow;
    int idColum;
    int f=0, id=0;
    int g=0;
    int h=0;

    bool closed=false;
    bool opened=false;
};

#endif // PATHFINDINGNODE_H
