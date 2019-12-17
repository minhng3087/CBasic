#include <stdio.h>
#include <stdlib.h>
#include "stack1.h"
#include "stack.h"
#include <string.h>

/*int doicoso(int n ,int b) {
    Node *stack = NULL;
    while(n!=0) {
        int m = n%b;
        push(&stack,&m,sizeof(int));
        n = n/b;
    }
    int i = 10;
    int m =  *(int*)peek(stack);
    *(int*)pop(&stack);
    while(!isEmpty(stack)) {
        m = m*i + *(int*)peek(stack);
        *(int*)pop(&stack);
    }

    return m;
}*/

void doicoso(int n,int v) {
    char a[16] = "0123456789ABCDEF";
    struct Stack* stack = createStack(strlen(a));
    while (n!=0)
    {
        push1(stack,n%v);
        n = n/v;
    }
    while (!isEmpty(stack))
    {
        Popstack(stack,&n);
        printf("%c",a[n]);
    }
}

int main() {
    doicoso(10,2);
    printf("\n");
}
