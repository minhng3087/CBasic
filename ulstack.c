#include "ulstack.h"
#include <stdlib.h>
#include <memory.h>

STACK_ELEM* newstack(STACK_DATA *data,size_t size){
	STACK_ELEM *node = (STACK_ELEM *) malloc(sizeof(STACK_ELEM));
	node->data = malloc(size);
	int i;
	for(i=0;i<size;i++)
		*(char *) (node->data + i) = *(char *) (data + i);
	node->next = NULL;
	return node;
}
void stInit(STACK* s) {
	*s = NULL;
}

void stDestroy(STACK* s) {
	while (*s) {
		STACK_ELEM* p = *s;
		*s = (*s)->next;
		free(p->data);
		free(p);
	}
}

void stPush(STACK* s, STACK_DATA data, int size) {
	STACK_ELEM* p = (STACK_ELEM*)malloc(sizeof(STACK_ELEM));
	p->data = malloc(size);
	memcpy(p->data, data, size);
	p->next = *s;

	*s = p;
}

void stPop(STACK* s) {
	if (stIsEmpty(s)) return;

	STACK_ELEM* p = *s;
	*s = (*s)->next;
	free(p->data);
	free(p);
}

STACK_DATA stTop(STACK* s) {
	return (*s)->data;
}

int stIsEmpty(STACK* s) {
	return *s == NULL;
}

int stIsFull(STACK* s) {
	return 0;
}

