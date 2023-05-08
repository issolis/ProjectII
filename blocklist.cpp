#include "blocklist.h"
#include <iostream>

blockList::blockList()
{

}
void blockList::insert(int nodesAmount){
    int i=nodesAmount;
    while(i!=0){
        blockNode *newNode=  new blockNode();
        newNode->item=new QGraphicsRectItem(0,0,20,20);
        newNode->item1=new QGraphicsPixmapItem(QPixmap (":poi.png"));
        newNode->id=nodesAmount-i;
        if(i==nodesAmount){
            head=newNode;
        }
        else{
            blockNode *aux=head;
            while(aux->next!=nullptr){
                aux=aux->next;
            }
            aux->next=newNode;
        }
       i--;
    }
}
void blockList::show(){
   blockNode *aux=head;
   while(aux!=nullptr){
       std::cout<<aux->id<<" ";
       aux=aux->next;
   }
}

blockNode* blockList::findNode(int id){
    blockNode *aux=head;
    while(aux!=nullptr){
        if(aux->id==id)
            return aux;
        aux=aux->next;
    }
    return aux;
}
