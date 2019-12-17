// binary tree with static data type

#ifndef __BTREE_H__
#define __BTREE_H__


typedef char BT_DATA;

struct _BT_NODE;

typedef struct _BT_NODE BT_NODE;

struct _BT_NODE {
	BT_DATA data;
	BT_NODE *left, *right;
};


typedef enum {
	BT_TRAVERSE_LVR,
	BT_TRAVERSE_LRV,
	BT_TRAVERSE_VLR,
	BT_TRAVERSE_VRL,
	BT_TRAVERSE_RLV,
	BT_TRAVERSE_RVL
} BT_TRAVERSE_MODE;




BT_NODE* btCreateNode(BT_DATA v);
BT_NODE* btCreateNodeLR(int v, BT_NODE* l, BT_NODE* r);
void btAddToLeft(BT_NODE* n, BT_NODE* c);
void btAddToRight(BT_NODE* n, BT_NODE* c);
void btDeleteNode(BT_NODE** n);
void btDeleteLeft(BT_NODE* n);
void btDeleteRight(BT_NODE* n);

int btIsLeaf(BT_NODE* n);

BT_NODE* btLeftMost(BT_NODE* n);
BT_NODE* btRightMost(BT_NODE* n);

int btCount(BT_NODE* n);
int btDepth(BT_NODE* n);

int btIsFull(BT_NODE* n);
int isLeaf(BT_NODE* n);
int btIsComplete(BT_NODE* n);

void btTraverseDFSRecursive(BT_NODE* n, BT_TRAVERSE_MODE mode, void (*func)(BT_NODE*, void*), void* user);
void btTraverseDFSIterativeLVR(BT_NODE* n, void (*func)(BT_NODE*, void*), void* user);
void btTraverseDFSIterativeVLR(BT_NODE* n, void (*func)(BT_NODE*, void*), void* user);
void btTraverseDFSIterativeLRV(BT_NODE* n, void (*func)(BT_NODE*, void*), void* user);
void btTraverseBFS(BT_NODE* n, void (*func)(BT_NODE*, void*), void* user);


void btPrintTree(BT_NODE* n);
void btPrintList(BT_NODE* n);


#endif // __BTREE_H__