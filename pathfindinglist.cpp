#include "pathfindinglist.h"
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include <QtGlobal>
#include <linkedlist.h>
#include <string>
pathFindingList::pathFindingList()
{
    head=nullptr;
}
pathFindingList pathFindingList::buildMatrix(int rows, int colums){
    pathFindingNode *newNode=  new pathFindingNode();
    head=newNode;
    head->idRow=0;
    head->idColum=0;
    head->id=1;
    this->rows=rows;
    this->colums=colums;


    pathFindingNode *auxColum=head;
    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;
    for (int i = 0; i<rows; i++){
        for(int j=0; j<colums; j++){
            pathFindingNode *node1= new pathFindingNode();
            pathFindingNode *node2= new pathFindingNode();

            if(i==0 && j!=colums-1){
                aux->right=node1;
            }
            else{
                if(j!=colums-1)
                    aux->right=aux1->right->down;

            }
            if(j!=colums-1){
                aux->right->idRow=i;
                aux->right->idColum=j+1;
                aux->right->left=aux;}

            if(i!=rows-1){
                aux->down=node2;
                aux->down->idColum=j;
                aux->down->idRow=i+1;
                aux->down->up=aux;
            }
            aux1=aux1->right;
            aux=aux->right;

        }
        aux1=auxColum;
        aux=auxColum->down;
        auxColum=auxColum->down;
    }

    definePos();
    pathFindingList list;
    list.head=head;
    return list;

}
void pathFindingList::definePos(){
    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;
    int i=0;
    while(i!=rows){
        while(aux!=nullptr){
            aux->id=aux->idRow * colums + aux->idColum+1;
            aux=aux->right;
        }
        aux=aux1->down;
        aux1=aux1->down;
        i++;
    }
}
void pathFindingList::show(){
    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;
    QTextStream cout(stdout);
    int i=0;
    while(i!=rows){
        while(aux!=nullptr){

            std::cout<<aux->closed<<" "<<aux->id<<" ";
            aux=aux->right;
        }
        std::cout<<std::endl;
        aux=aux1->down;
        aux1=aux1->down;
        i++;
    }
}

void pathFindingList:: defineH(int xF, int yF){
    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;

    int i=0;
    while(i!=rows){
        while(aux!=nullptr){

            aux->h= qAbs((aux->idRow)-(yF))+qAbs(aux->idColum-xF);
            aux=aux->right;
        }
        aux=aux1->down;
        aux1=aux1->down;
        i++;
    }
}
void pathFindingList:: findRoute(int beggining, int final){
    int xB=-1, yB;
    int xF=-1, yF;
    routeWeight=0;

    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;



    int i=0;
    while(i!=rows){
        while(aux!=nullptr){

            if(aux->id==beggining) {
                xB=aux->idColum;
                yB=aux->idRow;
                start=aux;
            }

            else if(aux->id==final){
                xF=aux->idColum;
                yF=aux->idRow;
                end=aux;
            }
            aux=aux->right;

            if(xB!=-1 && xF!=-1) break;


        }
        if(xB!=-1 && xF!=-1) break;

        aux=aux1->down;
        aux1=aux1->down;
        i++;
    }

    defineH(xF, yF);

    linkedList openList;

    openList.idFinal=final;
    start->closed=true;
    start->opened=true;

    pathFindingNode *auxiliar=start;
    while(!openList.routeFinded){
        if(auxiliar->right!=nullptr && !auxiliar->right->closed) {
            if(auxiliar->right->g!=0){
                if(auxiliar->g+10 < auxiliar->right->g){
                    auxiliar->right->g=auxiliar->g+10;
                    auxiliar->right->f=auxiliar->right->g+auxiliar->right->h;
                    auxiliar->right->parent=auxiliar;
                }
            }
            else{
                auxiliar->right->g=auxiliar->g+10;
                auxiliar->right->f=auxiliar->right->g+auxiliar->right->h;
                auxiliar->right->parent=auxiliar;
            }

            if(!auxiliar->right->opened)
                openList.insert(auxiliar->right);
            auxiliar->right->opened=true;
        }

        if(auxiliar->left!=nullptr && !auxiliar->left->closed) {
            if(auxiliar->left->g!=0){
                if(auxiliar->g+10 < auxiliar->left->g){
                    auxiliar->left->g=auxiliar->g+10;
                    auxiliar->left->parent=auxiliar;
                }
            }else{
                auxiliar->left->g=auxiliar->g+10;
                auxiliar->left->parent=auxiliar;
                auxiliar->left->f=auxiliar->left->g+auxiliar->left->h;
            }

            if(!auxiliar->left->opened)
                openList.insert(auxiliar->left);
            auxiliar->left->opened=true;
        }

        if(auxiliar->down!=nullptr && !auxiliar->down->closed) {
            if(auxiliar->down->g!=0){
                if(auxiliar->g+10 < auxiliar->down->g){
                    auxiliar->down->g=auxiliar->g+10;
                    auxiliar->down->f=auxiliar->down->g+auxiliar->down->h;
                    auxiliar->down->parent=auxiliar;
                }
            }
            else{
                auxiliar->down->g=auxiliar->g+10;
                auxiliar->down->f=auxiliar->down->g+auxiliar->down->h;
                auxiliar->down->parent=auxiliar;
            }

            if(!auxiliar->down->opened){
                openList.insert(auxiliar->down);}
            auxiliar->down->opened=true;
        }

        if(auxiliar->up!=nullptr && !auxiliar->up->closed) {
            if(auxiliar->up->g!=0){
                if(auxiliar->g+10 < auxiliar->up->g){
                    auxiliar->up->g=auxiliar->g+10;
                    auxiliar->up->f=auxiliar->up->g+auxiliar->up->h;
                    auxiliar->up->parent=auxiliar;
                }
            }else{
                auxiliar->up->g=auxiliar->g+10;
                auxiliar->up->f=auxiliar->up->g+auxiliar->up->h;
                auxiliar->up->parent=auxiliar;
            }

            if(!auxiliar->up->opened)
                openList.insert(auxiliar->up);
            auxiliar->up->opened=true;
        }

        if(openList.head!=nullptr)
            openList.findMin();
        else{
            break;
        }
        auxiliar=openList.min;
        auxiliar->closed=true;
        openList.deleteNode(auxiliar);



    }
    if(openList.head!=nullptr){
        pathFindingNode *auxP=end;
        QString route="";
        if(auxP!=nullptr){
            while(auxP->parent!=nullptr){
                route=QString::number(auxP->id )+"-"+ route;
                auxP=auxP->parent;
                routeWeight++;
            }
            route=QString::number(beggining)+"-"+route;
            //qDebug()<<route;
        }
    }


}

pathFindingNode* pathFindingList:: findNode(int id){
    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;
    QTextStream cout(stdout);
    int i=0;
    while(i!=rows){
        while(aux!=nullptr){
            if(aux->id==id)
                return aux;
            aux=aux->right;
        }
        aux=aux1->down;
        aux1=aux1->down;
        i++;
    }
    return aux;
}
void pathFindingList::makeItTrue(){
    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;
    QTextStream cout(stdout);
    int i=0;
    while(i!=rows){
        while(aux!=nullptr){
            aux->closed=false;
            aux->opened=false;
            aux->f=0;
            aux->g=0;
            aux->h=0;
            aux->parent=nullptr;
            aux=aux->right;
        }
        aux=aux1->down;
        aux1=aux1->down;
        i++;
    }
}

void pathFindingList:: freeEveryThing(){
    pathFindingNode *aux=head;
    pathFindingNode *aux1=head;
    QTextStream cout(stdout);
    int i=0;
    while(i!=rows){
        pathFindingNode *next;
        while(aux!=nullptr){
            next=aux->right;
            delete aux;
            aux=next;
        }

        aux=aux1->down;
        aux1=aux1->down;
        i++;
    }
    head=nullptr;
}
