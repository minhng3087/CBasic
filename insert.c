#include <stdio.h>
#include <stdlib.h>

typedef int data;
typedef struct node LLIST_ELEM, *LLIST; 

struct node
{
    int data;
    LLIST_ELEM *next;
};


void printList(struct node *l){
    while(l!=NULL){
        printf(" %d ",l->data);
        l = l->next;
    }
    printf("\n");

}


void inserthead(LLIST *l, int v) {
    LLIST_ELEM* e = (LLIST_ELEM*)malloc(sizeof(LLIST_ELEM));
    e ->data = v;
    e ->next = (*l);
    (*l) = e ;
    if(*l == NULL)
    {
        *l = e;
        return;
    }
}

void inserttail(LLIST *l, int v){
    LLIST_ELEM* e = (LLIST_ELEM*)malloc(sizeof(LLIST_ELEM));
    e ->data = v;
    e ->next = NULL;
    if(*l == NULL)
    {
        *l = e;
        return;
    }
    LLIST_ELEM *p = *l;
    for (p = *l;  p -> next != NULL; p = p -> next);
    p -> next = e;
}

void insertafter(LLIST *l,LLIST_ELEM *a,int v){
    LLIST_ELEM* e = (LLIST_ELEM*)malloc(sizeof(LLIST_ELEM));
    if(!a) return;
    e -> data = v;
    e -> next = a -> next;
    a -> next = e;

}




int main(){
    struct node* l = NULL;
    inserthead(&l,12);
    inserthead(&l,13);
    inserttail(&l,14);
    inserttail(&l,15);
    insertafter(&l,l -> next -> next  ,30);

    printList(l);

}

