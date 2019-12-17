#include <stdio.h>
#include <stdlib.h>

typedef int data;
typedef struct node LLIST_ELEM,*LLIST;

struct node {
    int data;
    LLIST_ELEM *next;
};

void printList(struct node *l) {
    while (l!=NULL){
        printf(" %d ",l->data);
        l = l->next;
    }
    printf("\n");

}

void inserthead(LLIST *l,int v) {
    LLIST_ELEM *e = (LLIST_ELEM*)malloc(sizeof(LLIST_ELEM));
    e ->data = v;
    e ->next = (*l);
    (*l) = e; 
    if(*l == NULL){
        *l = e;
        return;
    }
}

void deletehead(LLIST *l) {
    if(*l == NULL) {
        (*l) = NULL ;
        return;
    }
    LLIST_ELEM* p = (*l) ->next;
    free(*l);
    (*l) = p;
}
 void deletetail(LLIST *l) {
    if(*l == NULL) {
        (*l) = NULL;
        return;
    }
    if((*l) -> next == NULL) {
        free(*l);
        (*l) = NULL;
        return;
    }
    LLIST_ELEM *p;
    for(p = (*l);p->next->next;p = p->next);
    free(p->next);
    p->next = NULL;
 }

 void deleteafter(LLIST *l,LLIST_ELEM *a) {
    if(a == NULL || a->next == NULL) {
        return;
    }
    LLIST_ELEM* p = a->next;
    a->next = p->next;
    free(p);

 }



int main(){
    struct node* l = NULL;
    inserthead(&l,10);
    inserthead(&l,11);
    inserthead(&l,12);
    inserthead(&l,15);
    inserthead(&l,16);
    inserthead(&l,17);

    deletehead(&l);\
    deletetail(&l);
    deleteafter(&l,l);






    printList(l);

}