#include <stdio.h>
#include <stdlib.h>
#include "stack1.h"
#include <math.h>
#include <string.h>

int reverseINT(int number) {
    Node *stack = NULL ;
    while(number!=0) {
        int a = number%10;
        push(&stack,&a,sizeof(int));
        number = number/10;
    }
    int i = 1;
    int newnum = 0;
    while(!isEmpty(stack)) {
        newnum = newnum + (*(int*)peek(stack))*i;
        *(int*)pop(&stack);
        i = i*10;
    }
    return newnum;
}

void reverseSTRING(char *s) {
    Node *stack = NULL;
    for(int i=0;i<strlen(s);i++) {
        push(&stack,&*(s+i),sizeof(char));
    }
    for(int i=0;i<strlen(s);i++) {
        *(s+i) = *(char*)peek(stack);
        *(char*)pop(&stack);
    }

}

int main() {
   printf("%d\n",reverseINT(1002));
   char s[] = "abc def";
   reverseSTRING(s);
   printf("%s\n",s);
}