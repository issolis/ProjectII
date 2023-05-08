#include "linkedlist.h"


linkedList::linkedList()
{

}

void linkedList:: insert(pathFindingNode* id){
    node *newNode= new node(id);
    node *aux = head;
    bool insertable=true;
    if(id->id==idFinal) routeFinded=true;

    if(head==nullptr){
        insertable=false;
        head= newNode;
    }

    while(insertable && aux->next!=nullptr)
        aux=aux->next;
    if(insertable)
        aux->next=newNode;
    findMin();
}
void linkedList::deleteNode(pathFindingNode *Node){

    node *aux = head;
    node *aux1=head;
    if(head!=nullptr){
        if(head->id==Node) {
            if(head->next!=nullptr){
                head=head->next;
            }
            else
                head=nullptr;
        }
        aux=head;
        while(aux!=nullptr){

            if(aux->id==Node){
                if(aux->next!=nullptr)
                    aux1->next=aux->next;
                else
                    aux1->next=nullptr;
                break;
            }
            aux1=aux;
            aux=aux->next;
        }
    }
}
void linkedList:: findMin(){

        pathFindingNode *min=head->id;
        node *aux=head;

        while(aux!=nullptr){
            if(min->f>aux->id->f)
                min=aux->id;
            aux=aux->next;
        }
        this->min=min;


}
