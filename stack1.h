#include <stdio.h>


#ifndef __STACK1_H__
#define __STACK1_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StackNode {
	void *data;
	struct StackNode *next;
}Node;

Node* newNode(void *data,size_t size);
int isEmpty(Node *top);
void push(Node **top,void *item,size_t size);
void *pop(Node **top);
void *peek(Node *top);
void printString(void *s);
void printChar(void *c);
void printInt(void *n);
void printStack(Node *top, void (*fptr)(void *));



#ifdef __cplusplus
}
#endif

#endif

