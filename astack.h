// array-based stack with static data type

#ifndef __ASTACK_H__
#define __ASTACK_H__

#ifdef __cplusplus
extern "C" {
#endif


typedef int STACK_DATA;


#define MAX_ELEMENTS	20

typedef struct {
	STACK_DATA elements[MAX_ELEMENTS];
	int top;
} STACK;


void stInit(STACK* s);
void stDestroy(STACK* s);

void stPush(STACK* s, STACK_DATA data);
void stPop(STACK* s);
STACK_DATA stTop(STACK* s);

int stIsEmpty(STACK* s);
int stIsFull(STACK* s);




#ifdef __cplusplus
}
#endif

#endif // __ASTACK_H__