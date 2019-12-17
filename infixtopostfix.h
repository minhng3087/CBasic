#ifndef __INFIXTOPOSTFIX__
#define __INFIXTOPOSTFIX__

#ifdef __cplusplus
extern "C" {
#endif

struct Stack* createStack( unsigned capacity );
int isEmpty(struct Stack* stack) ;
char peek(struct Stack* stack);
char pop(struct Stack* stack);
void push(struct Stack* stack, char op);
int isOperand(int ch);
int Prec(char ch);
int infixToPostfix(char* exp);



#ifdef __cplusplus
}
#endif
#endif