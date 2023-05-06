#ifndef LISTID_H
#define LISTID_H
#include <nodeid.h>

class listID
{
public:
    listID();
    void insert(int id);
    nodeID *head=nullptr;
    void show();
    void deleteFirst();
    int numberElements=0;
};

#endif // LISTID_H
