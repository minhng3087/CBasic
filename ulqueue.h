// list-based queue with universal data type

#ifndef __ULQUEUE_H__
#define __ULQUEUE_H__

#ifdef __cplusplus
extern "C" {
#endif


typedef void* QUEUE_DATA;


struct _QUEUE_ELEM;
typedef struct _QUEUE_ELEM QUEUE_ELEM;

struct _QUEUE_ELEM {
	QUEUE_DATA data;
	QUEUE_ELEM* next;
};

typedef struct {
	QUEUE_ELEM* head;
	QUEUE_ELEM* tail;
} QUEUE;

void qInit(QUEUE* s);
void qDestroy(QUEUE* s);

void qEnqueue(QUEUE* s, QUEUE_DATA data, int size);
void qDequeue(QUEUE* s);
QUEUE_DATA qHead(QUEUE* s);

int qIsEmpty(QUEUE* s);
int qIsFull(QUEUE* s);




#ifdef __cplusplus
}
#endif

#endif // __ULQUEUE_H__