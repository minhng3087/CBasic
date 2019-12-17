#include "aqueue.h"


void qInit(QUEUE* s) {
	s->head = 0;
	s->count = 0;
}

void qDestroy(QUEUE* s) {
	s->head = 0;
	s->count = 0;
}

void qEnqueue(QUEUE* s, QUEUE_DATA data) {
	if (qIsFull(s)) return;

	s->elements[(s->head + s->count) % MAX_ELEMENTS] = data;
	s->count++;
}

void qDequeue(QUEUE* s) {
	if (qIsEmpty(s)) return;

	s->count--;
	if (++ s->head == MAX_ELEMENTS) s->head = 0;
}

QUEUE_DATA qHead(QUEUE* s) {
	return s->elements[s->head];
}

int qIsEmpty(QUEUE* s) {
	return s->count == 0;
}

int qIsFull(QUEUE* s) {
	return s->count == MAX_ELEMENTS;
}

