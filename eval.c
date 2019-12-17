#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _STACK
{
	char oper[1024];
	int index;
}STACKOPER;

typedef struct __STACK
{
    int value[1024];
    int indexx;
}STACKVALUE;


void InitStackOper(STACKOPER* stack)
{
	if (stack != NULL)
	{
		stack->index = -1;
	}
}

void InitStackValue(STACKVALUE* stack)
{
	if (stack != NULL)
	{
		stack->indexx = -1;
	}
} 
int IsEmptyStackOper(STACKOPER* stack)
{
	if (stack != NULL)
		return stack->index == -1;
	else 
		return 1;
}

int IsEmptyStackValue(STACKVALUE* stack)
{
	if (stack != NULL)
		return stack->indexx == -1;
	else 
		return 1;
}


void PushOper(STACKOPER* stack, char oper)              //
{
	if (stack != NULL)
	{
		stack->oper[++stack->index] = oper;
	}
}

void PushValue(STACKVALUE* stack,int value) {
    if (stack != NULL)
	{
		stack->value[++stack->indexx] = value;
	}
}

int PopOper(STACKOPER* stack)
{
	if (stack != NULL && !IsEmptyStackOper(stack))
		return stack->oper[stack->index--];
	else
		return 0;
}

int PopValue(STACKVALUE* stack)
{
	if (stack != NULL && !IsEmptyStackValue(stack))
		return stack->value[stack->indexx--];
	else
		return 0;
}


char TopOper(STACKOPER* stack)                  
{
	if (stack != NULL && !IsEmptyStackOper(stack))
		return stack->oper[stack->index];
	else
		return 0;		
}

int TopValue(STACKVALUE* stack)
{
    if (stack != NULL && !IsEmptyStackValue(stack))
		return stack->value[stack->indexx];
	else
		return 0;
}

int Priority(char oper) //thứ tự ưu tiên phép toán
{
	switch (oper)
	{
		case '+':
		case '-':
			return 0;
		case '*':
		case '/':
			return 1;
        case '^':
            return 2;
		default:
			return -1;
	}
}


int pow1(int n, int v) {
    int m = 1;
    for(int i=1;i<=v;i++) {
        m = n * m;
    }
    return m;
}


int applyOp(int a, int b, char op){ 
    switch(op){ 
        case '+': return a + b; 
        case '-': return a - b; 
        case '*': return a * b; 
        case '/': return a / b; 
        case '^': return pow1(a,b);
    } 
} 

STACKVALUE stackvalue;
STACKOPER stackoper;
int evaluate(char *tokens){ 
    int i; 
    InitStackOper(&stackoper);
    InitStackValue(&stackvalue);
      
    for(i = 0; i < strlen(tokens); i++){ 
        
        if(tokens[i] == ' ') 
            continue; 
         
        else if(tokens[i] == '('){ 
            PushOper(&stackoper,tokens[i]); 
        } 
          
        else if(isdigit(tokens[i])){ 
            int val = 0; 
            while(i < strlen(tokens) &&  
                        isdigit(tokens[i])) 
            { 
                val = (val*10) + (tokens[i]-'0'); 
                i++; 
            } 
              
            PushValue(&stackvalue,val); 
        } 
         
        else if(tokens[i] == ')') 
        { 
            while(!IsEmptyStackOper(&stackoper) && TopOper(&stackoper) != '(') 
            { 
                int val2 = TopValue(&stackvalue); 
               PopValue(&stackvalue); 
                  
                int val1 = TopValue(&stackvalue);
                PopValue(&stackvalue);
                  
                char op = TopOper(&stackoper); 
                PopOper(&stackoper);
                  
                PushValue(&stackvalue,applyOp(val1, val2, op)); 
            } 
              
           
            if(!IsEmptyStackOper(&stackoper)) 
               PopOper(&stackoper); 
        } 
          
        
        else
        {  
            while(!IsEmptyStackOper(&stackoper) && Priority(TopOper(&stackoper)) 
                                >= Priority(tokens[i])){ 
                int val2 = TopValue(&stackvalue); 
                PopValue(&stackvalue); 
                  
                int val1 = TopValue(&stackvalue); 
                PopValue(&stackvalue); 
                  
                char op = TopOper(&stackoper);
                PopOper(&stackoper);
                  
                PushValue(&stackvalue,applyOp(val1, val2, op)); 
            } 
              
            PushOper(&stackoper,tokens[i]); 
        } 
    } 

    while(!IsEmptyStackOper(&stackoper)){ 
        int val2 = TopValue(&stackvalue); 
                PopValue(&stackvalue); 
                  
        int val1 = TopValue(&stackvalue); 
        PopValue(&stackvalue); 
                  
        char op = TopOper(&stackoper);
        PopOper(&stackoper);
                  
        PushValue(&stackvalue,applyOp(val1, val2, op)); 
    } 
      
    return TopValue(&stackvalue); 
}

int main() {
    char s[] = "100 * ( 2 + 12 ) / 14";
    printf("%d",evaluate(s));


}
