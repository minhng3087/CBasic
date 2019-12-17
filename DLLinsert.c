#include <stdio.h>
#include <stdlib.h>

typedef int data;
typedef struct node LLIST_ELEM,*DLLIST;

struct node {
    int data;
    LLIST_ELEM *next;
    LLIST_ELEM *prev;
};

void printList1(struct node *l) { //forward direction
    while(l!=NULL) {
        printf(" %d ",l->data);
        //last = l;
        l = l->next;
        
    }
    printf("\n");
}

void printList2(struct node *l) { //reverse direction
    struct node *last;
    while(l!=NULL) {
        last = l;
        l = l->next;
    }
    while(last != NULL) {
        printf(" %d ",last->data);
        last = last->prev;
    }
    printf("\n");
}

void inserthead1(DLLIST *l,int v) {
    LLIST_ELEM *new = (LLIST_ELEM*)malloc(sizeof(LLIST_ELEM));
    new -> data = v;
    new -> next = (*l);
    new -> prev = NULL;
    if((*l) != NULL)
    (*l)->prev = new;
    (*l) = new;
}

void inserttail(DLLIST *l,int v) {
    LLIST_ELEM *new = (LLIST_ELEM*)malloc(sizeof(LLIST_ELEM));
    new -> data = v;
    new -> next = NULL;
    if(*l == NULL) {
        new -> prev = NULL;
        *l = new;
        return;
    }
    LLIST_ELEM *p = *l;
    for(p = *l;p->next != NULL;p=p->next); 
        p ->next = new;
        new -> prev = p;
    
}

void insertafter(DLLIST *l,LLIST_ELEM *a,int v) {
    LLIST_ELEM *new = (LLIST_ELEM*)malloc(sizeof(LLIST_ELEM));
    if(!a) return;
    new -> data = v;
    new -> next = a -> next;
    a -> next = new;
    new -> prev = a;
    if(new->next != NULL) {
        new -> next -> prev = new;
    }
}

void insertbefore(DLLIST *l,LLIST_ELEM *a, int v) {
    LLIST_ELEM *new = (LLIST_ELEM*)malloc(sizeof(LLIST_ELEM));
    if(!a) return;
    new -> data = v;
    new -> prev = a -> prev;
    a -> prev = new;
    new -> next = a;
    if(new->prev != NULL) {
        new -> prev -> next = new;
    }
    else (*l) = new;

}

int main(){
    struct node* l = NULL;
    inserthead1(&l,10);     
    inserthead1(&l,12);
    inserthead1(&l,13);
    
    
    insertbefore(&l,l,50);

    
    printList1(l);

}
