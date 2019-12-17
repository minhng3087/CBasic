// array-based queue with static data type

#ifndef __AQUEUE_H__
#define __AQUEUE_H__

#ifdef __cplusplus
extern "C" {
#endif


typedef int QUEUE_DATA;


#define MAX_ELEMENTS	20

typedef struct {
	QUEUE_DATA elements[MAX_ELEMENTS];
	int head;
	int count;
} QUEUE;


void qInit(QUEUE* s);
void qDestroy(QUEUE* s);

void qEnqueue(QUEUE* s, QUEUE_DATA data);
void qDequeue(QUEUE* s);
QUEUE_DATA qHead(QUEUE* s);

int qIsEmpty(QUEUE* s);
int qIsFull(QUEUE* s);




#ifdef __cplusplus
}
#endif

#endif // __AQUEUE_H__