#include <stdio.h>
#include <stdlib.h>

typedef int data;
typedef struct node LLIST_ELEM,*LLIST;

struct node {
    int data;
    LLIST_ELEM *next;
};

void printList(struct node *l) {
    while(l != NULL) {
        printf(" %d ",l->data);
        l = l -> next;
    }
    printf("\n");
}

void inserthead(LLIST *l,int v) {
    LLIST_ELEM *new = (LLIST_ELEM*)malloc(sizeof(LLIST_ELEM));
    new -> data = v;
    new -> next = (*l);
    if((*l)==NULL) {
        (*l) = new;
        return;
    }
    (*l) = new;

}

void llReverse1(LLIST *l) {
    LLIST_ELEM *prev = NULL;
    LLIST_ELEM *next = NULL;
    LLIST_ELEM *curr = (*l);
    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    (*l) = prev;
}

LLIST abc(LLIST l) {
    if(l->next != NULL){
    abc(l->next);
    l->next->next = l;
    l->next = NULL;
    }
    return l;

}

void llReverse2(LLIST *l) {  //do recursively
    *l = abc(*l);
}

int main() {
    struct node *l = NULL;
    inserthead(&l,10);
    inserthead(&l,12);
    inserthead(&l,13);

    printList(l);

    llReverse1(&l);

    printList(l);
}