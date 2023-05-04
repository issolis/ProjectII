#ifndef PATHFINDINGLIST_H
#define PATHFINDINGLIST_H

#include "pathfindingnode.h"

class pathFindingList
{
public:
    pathFindingList();
    pathFindingNode *head=nullptr;
    pathFindingList buildMatrix(int rows, int colums);
    void show();
    int rows, colums;
    void definePos();

    void findRoute(int beggining, int final );
    int * findBeggining(int beggining);
    void defineH(int xF, int yF);

};

#endif // PATHFINDINGLIST_H
