#ifndef BLOCKLIST_H
#define BLOCKLIST_H
#include <blocknode.h>

class blockList
{
public:
    blockList();
    blockNode *head=nullptr;
    void insert(int nodesAmount);
    void show();


};

#endif // BLOCKLIST_H
