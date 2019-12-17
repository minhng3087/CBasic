

#ifndef __LLIST_H__
#define __LLIST_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef int LLIST_DATA;


struct _LIST_ELEM;
typedef struct _LIST_ELEM LIST_ELEM, *LLIST;

struct _LIST_ELEM {
	LLIST_DATA data;
	LIST_ELEM* next;
};

typedef void (*LLCALLBACK)(LLIST_DATA, void*);


void llInit(LLIST* l);

void llInsertHead(LLIST* l, LLIST_DATA data);
void llInsertTail(LLIST* l, LLIST_DATA data);
void llInsertAfter(LLIST* l, LIST_ELEM* a, LLIST_DATA data);

void llDeleteHead(LLIST* l);
void llDeleteTail(LLIST* l);
void llDeleteAfter(LLIST* l, LIST_ELEM* a);
void llDeleteAll(LLIST* l);

LIST_ELEM* llSeek(LLIST l, int i);
void llForEach(LLIST l, LLCALLBACK func, void* user);
int llLength(LLIST l);

void printList(LLIST l);



#ifdef __cplusplus
}
#endif


#endif // __LLIST_H__