#include "llist.h"
#include <stdlib.h>
#include <stdio.h>


void llInit(LLIST* l) {
	*l = NULL;
}


void llInsertHead(LLIST* l, LLIST_DATA data) {
	LIST_ELEM* e = (LIST_ELEM*)malloc(sizeof(LIST_ELEM));
	e->data = data;
	e->next = *l;
	*l = (LLIST)e;
}



void llInsertTail(LLIST* l, LLIST_DATA data) {
	LIST_ELEM* e = (LIST_ELEM*)malloc(sizeof(LIST_ELEM));
	e->data = data;
	e->next = NULL;

	if (!*l) {
		*l = e;
		return;
	}

	LIST_ELEM* p;
	for (p = *l; p->next; p = p->next) ;
	p->next = e;
}


void llInsertAfter(LLIST* l, LIST_ELEM* a, LLIST_DATA data) {
	if (!a) return;

	LIST_ELEM* e = (LIST_ELEM*)malloc(sizeof(LIST_ELEM));
	e->data = data;
	e->next = a->next;
	a->next = (LLIST)e;
}



void llDeleteHead(LLIST* l) {
	if (!*l) {
		*l = NULL;
		return;
	}

	LIST_ELEM* p = (*l)->next;
	free(*l);
	*l = (LLIST)p;
}


void llDeleteTail(LLIST* l) {
	if (!*l) {
		*l = NULL;
		return;
	}

	if (!(*l)->next) {
		free(*l);
		*l = NULL;
		return;
	}

	LIST_ELEM* p;
	for (p = *l; p->next->next; p = p->next) ;
	free(p->next);
	p->next = NULL;
}


void llDeleteAfter(LLIST* l, LIST_ELEM* a) {
	if (!a || !a->next) return;

	LIST_ELEM* p = a->next;
	a->next = p->next;

	free(p);
}



void llDeleteAll(LLIST* l) {
	LIST_ELEM *p, *i;
	for (i = *l; i; i = p) {
		p = i->next;
		free(i);
	}
	*l = NULL;
}



LIST_ELEM* llSeek(LLIST l, int i) {
	for (; i>0 && l; i--)
		l = l->next;
	return (LIST_ELEM*)l;
}


void llForEach(LLIST l, LLCALLBACK func, void* user) {
	for (; l; l = l->next)
		func(l->data, user);
}


int llLength(LLIST l) {
	int c;
	for (c = 0; l; c++)
		l = l->next;
	return c;
}

void printList(LLIST l){
    while(l!=NULL){
        printf(" %d ",l->data);
        l = l->next;
    }
    printf("\n");

}