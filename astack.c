#include "astack.h"


void stInit(STACK* s) {
	s->top = 0;
}

void stDestroy(STACK* s) {
	s->top = 0;
}

void stPush(STACK* s, STACK_DATA data) {
	if (stIsFull(s)) return;

	s->elements[s->top] = data;
	s->top++;
}

void stPop(STACK* s) {
	if (stIsEmpty(s)) return;

	s->top--;
}

STACK_DATA stTop(STACK* s) {
	return s->elements[s->top-1];
}

int stIsEmpty(STACK* s) {
	return s->top == 0;
}

int stIsFull(STACK* s) {
	return s->top == MAX_ELEMENTS;
}

