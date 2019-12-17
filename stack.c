#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1 ; 
} 

struct Stack* createStack( unsigned capacity ) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
  
    if (!stack)  
        return NULL; 
  
    stack->top = -1; 
    stack->capacity = capacity; 
  
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); 
  
    if (!stack->array) 
        return NULL; 
    return stack; 
}

int Popstack(struct Stack* stack,int *dataout) {
    if(stack->capacity == 0) return 0;
    *dataout = stack->array[stack->top];
    (stack->capacity)--;
    (stack->top)--;
    return 1;
}


char pop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return '$'; 
} 

void push1(struct Stack* stack,int data) {
    stack->array[++stack->top] = data;

}
char peek(struct Stack* stack) 
{ 
    return stack->array[stack->top]; 
}  

int peek1(struct Stack* stack)
{
    return stack->array[stack->top];
}

void pop1(struct Stack* stack) {
    if (isEmpty(stack)) return;
	stack->top--;
}
void push(struct Stack* stack, char op) 
{ 
    stack->array[++stack->top] = op; 
} 
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity-1;
}
