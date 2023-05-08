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
    blockNode *findNode(int id);


};

#endif // BLOCKLIST_H
