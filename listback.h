#ifndef LISTBACK_H
#define LISTBACK_H
#include "nodeback.h"


class listBack
{
public:
    nodeBack* head;
    listBack();
    void add(int x, int y);
    void deleteNode();
    bool esvacia();
    void printPath(listBack path);
    int length();

};

#endif // LISTBACK_H
