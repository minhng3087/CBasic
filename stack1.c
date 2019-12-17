#include <stdio.h>
#include <stdlib.h>
#include "stack1.h"


Node* newNode(void *data,size_t size) {
	Node *node = (Node *) malloc(sizeof(Node));
	node->data = malloc(size);
	int i;
	for(i=0;i<size;i++)
		*(char *) (node->data + i) = *(char *) (data + i);
	node->next = NULL;
	return node;
}
int isEmpty(Node *top) {
	return !top;
}
void push(Node **top,void *item,size_t size) {
	Node *node = newNode(item,size);
	if(node == NULL) {
		printf("Stack overflow");
		return;
	}
	node->next = *top;
	*top = node;
}
void *pop(Node **top) {
	if(isEmpty(*top)) {
		printf("Stack underflow. Invalid String\n");
		exit(1);
	}
	Node *temp = *top;
	*top = (*top)->next;
	void *popped = temp->data;
	free(temp);
	return popped;
}
void *peek(Node *top) {
	if(isEmpty(top)) {
		printf("Stack underflow. Invalid String\n");
		exit(1);
	}
	return top->data;
}
void printString(void *s) {
	printf("%s ",(char *)s);
}
void printChar(void *c) {
	printf("%c ",*(char *)c);
}
void printInt(void *n) {
	printf("%d ",*(int *)n);
}
void printStack(Node *top, void (*fptr)(void *)) {
	while(top) {
		(*fptr)(top->data);
		top = top->next; 
	}
	printf("\n");
}