#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>
//#include "infixtopostfix.h"
#include <math.h>
#include "stack.h"

int pow1(int x,int y) {
    int m=1;
    for(int i=1;i<=y;i++){
        m = m*x;
    }
    return m;
}


char isOperator(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

int Prec(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 
  
    case '*': 
    case '/': 
        return 2; 
  
    case '^': 
        return 3; 
    } 
    return -1; 
}  

int isOperand(int ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
} 
int infixToPostfix(char* exp) 
{ 
    int i, k; 
    struct Stack* stack = createStack(strlen(exp)); 
    if(!stack)
        return -1 ; 
  
    for (i = 0, k = -1; exp[i]; ++i) 
    { 
        if (isOperand(exp[i])) 
            exp[++k] = exp[i]; 
        else if (exp[i] == '(') 
            push(stack, exp[i]); 
        else if (exp[i] == ')') 
        { 
            while (!isEmpty(stack) && peek(stack) != '(') 
                exp[++k] = pop(stack); 
            if (!isEmpty(stack) && peek(stack) != '(') 
                return -1;              
            else
                pop(stack); 
        } 
        else
        { 
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack))) 
                exp[++k] = pop(stack); 
            push(stack, exp[i]); 
        } 
  
    } 
    while (!isEmpty(stack)) 
        exp[++k] = pop(stack ); 
  
    exp[++k] = '\0'; 
} 

int main() {
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    printf("%s",exp);
}
