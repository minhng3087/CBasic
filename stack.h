#ifndef __STACK_H__
#define __STACK_H__

#ifdef __cplusplus
extern "C" {
#endif

struct Stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

//struct Stack* createStack1( unsigned capacity );
int isEmpty(struct Stack* stack);
struct Stack* createStack( unsigned capacity );
char pop(struct Stack* stack);
void push1(struct Stack* stack,int data);
char peek(struct Stack* stack) ;
int peek1(struct Stack* stack);
void pop1(struct Stack* stack);
void push(struct Stack* stack, char op);
int isFull(struct Stack* stack);
int Popstack(struct Stack* stack,int *dataout);
#ifdef __cplusplus
}
#endif

#endif