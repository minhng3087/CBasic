// list-based stack with universal data type

#ifndef __ULSTACK_H__
#define __ULSTACK_H__

#ifdef __cplusplus
extern "C" {
#endif



typedef void* STACK_DATA;


struct _STACK_ELEM;
typedef struct _STACK_ELEM STACK_ELEM, *STACK;

struct _STACK_ELEM {
	void* data;
	STACK_ELEM* next;
};

STACK_ELEM* newstack(STACK_DATA *data,size_t size);
void stInit(STACK* s);
void stDestroy(STACK* s);

void stPush(STACK* s, STACK_DATA data, int size);
void stPop(STACK* s);
STACK_DATA stTop(STACK* s);

int stIsEmpty(STACK* s);
int stIsFull(STACK* s);




#ifdef __cplusplus
}
#endif

#endif // __ULSTACK_H__