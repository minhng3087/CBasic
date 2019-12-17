#include "ulqueue.h"
#include <stdlib.h>
#include <memory.h>


void qInit(QUEUE* s) {
	s->head = NULL;
	s->tail = NULL;
}

void qDestroy(QUEUE* s) {
	while (s->head) {
		QUEUE_ELEM* p = s->head;
		s->head = p->next;
		free(p->data);
		free(p);
	}

	s->head = NULL;
	s->tail = NULL;
}

void qEnqueue(QUEUE* s, QUEUE_DATA data, int size) {
	if (qIsFull(s)) return;

	QUEUE_ELEM* p = (QUEUE_ELEM*)malloc(sizeof(QUEUE_ELEM));
	p->data = malloc(size);
	memcpy(p->data, data, size);
	p->next = NULL;

	if (s->tail) s->tail->next = p;
	s->tail = p;

	if (!s->head) s->head = p;
}

void qDequeue(QUEUE* s) {
	if (qIsEmpty(s)) return;

	QUEUE_ELEM* p = s->head;
	s->head = p->next;
	free(p->data);
	free(p);
}

QUEUE_DATA qHead(QUEUE* s) {
	return s->head->data;
}

int qIsEmpty(QUEUE* s) {
	return s->head == NULL;
}

int qIsFull(QUEUE* s) {
	return 0;
}

