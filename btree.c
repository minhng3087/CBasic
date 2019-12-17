#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "ulstack.h"
#include "ulqueue.h"


BT_NODE* btCreateNode(BT_DATA v) {
	BT_NODE* n = (BT_NODE*)malloc(sizeof(BT_NODE));
	n->data = v;
	n->left = n->right = NULL;
	return n;
}

BT_NODE* btCreateNodeLR(int v, BT_NODE* l, BT_NODE* r) {
	BT_NODE* n = (BT_NODE*)malloc(sizeof(BT_NODE));
	n->data = v;
	n->left = l;
	n->right = r;
	return n;
}


void btAddToLeft(BT_NODE* n, BT_NODE* c) {
	if (n == NULL) return;
	n->left = c;
}

void btAddToRight(BT_NODE* n, BT_NODE* c) {
	if (n == NULL) return;
	n->right = c;
}

void btDeleteNode(BT_NODE** n) {
	if (n == NULL || *n == NULL) return;

	btDeleteNode(&(*n)->left);
	btDeleteNode(&(*n)->right);

	free(*n);
	*n = NULL;
}

void btDeleteLeft(BT_NODE* n) {
	if (n == NULL) return;
	btDeleteNode(&n->left);
}

void btDeleteRight(BT_NODE* n) {
	if (n == NULL) return;
	btDeleteNode(&n->right);
}

int btIsLeaf(BT_NODE* n) {
	return n->left == NULL && n->right == NULL;
}

BT_NODE* btLeftMost(BT_NODE* n) {
	while (n->left != NULL) n = n->left;
	return n;
}

BT_NODE* btRightMost(BT_NODE* n) {
	while (n->right != NULL) n = n->right;
	return n;
}

int btCount(BT_NODE* n) {
	if (n == NULL) return 0;
	return 1 + btCount(n->left) + btCount(n->right);
}


int btDepth(BT_NODE* n) {   //height
	if (n == NULL) return 0;

	int l = btDepth(n->left),
		r = btDepth(n->right);
	return (l > r ? l : r) + 1;
}

int btIsFull(BT_NODE* n) {
	int c = (n->left != NULL) + (n->right != NULL);
	if (c == 1) return 0;
	if (c == 0) return 1;

	return btIsFull(n->left) && btIsFull(n->right);
}

int btLeaf(BT_NODE* n) {
	if(n == NULL) return 0;
	if(n->left == NULL && n->right == NULL) return 1;
	else 
	return btLeaf(n->left) + btLeaf(n->right);
}



int _checkComplete(BT_NODE* n, int i, int count) {
	if (n == NULL) return 1;
	if (i >= count) return 0;

	return _checkComplete(n->left, 2*i + 1, count)
		&& _checkComplete(n->right, 2*i + 2, count);
}

int btIsComplete(BT_NODE* n) {
	return _checkComplete(n, 0, btCount(n));
}


void btTraverseDFSRecursive(BT_NODE* n, BT_TRAVERSE_MODE mode, void (*func)(BT_NODE*, void*), void* user) {
	if (n == NULL) return;

	switch (mode) {
	case BT_TRAVERSE_LVR:
		if (n->left != NULL) btTraverseDFSRecursive(n->left, mode, func, user);
		func(n, user);
		if (n->right != NULL) btTraverseDFSRecursive(n->right, mode, func, user);
		break;
	case BT_TRAVERSE_LRV:
		if (n->left != NULL) btTraverseDFSRecursive(n->left, mode, func, user);
		if (n->right != NULL) btTraverseDFSRecursive(n->right, mode, func, user);
		func(n, user);
		break;
	case BT_TRAVERSE_RLV:
		if (n->right != NULL) btTraverseDFSRecursive(n->right, mode, func, user);
		if (n->left != NULL) btTraverseDFSRecursive(n->left, mode, func, user);
		func(n, user);
		break;
	case BT_TRAVERSE_RVL:
		if (n->right != NULL) btTraverseDFSRecursive(n->right, mode, func, user);
		func(n, user);
		if (n->left != NULL) btTraverseDFSRecursive(n->left, mode, func, user);
		break;
	case BT_TRAVERSE_VLR:
		func(n, user);
		if (n->left != NULL) btTraverseDFSRecursive(n->left, mode, func, user);
		if (n->right != NULL) btTraverseDFSRecursive(n->right, mode, func, user);
		break;
	case BT_TRAVERSE_VRL:
		func(n, user);
		if (n->right != NULL) btTraverseDFSRecursive(n->right, mode, func, user);
		if (n->left != NULL) btTraverseDFSRecursive(n->left, mode, func, user);
		break;
	}
}


void btTraverseDFSIterativeLVR(BT_NODE* n, void (*func)(BT_NODE*, void*), void* user) {
	if (n == NULL) return;

	STACK s;
	stInit(&s);

	for (;;) {
		for (; n != NULL; n = n->left)
			stPush(&s, &n, sizeof(BT_NODE*));
		if (stIsEmpty(&s)) break;

		n = *(BT_NODE**)stTop(&s);
		stPop(&s);
		func(n, user);

		n = n->right;
	}

	stDestroy(&s);
}


void btTraverseDFSIterativeVLR(BT_NODE* n, void (*func)(BT_NODE*, void*), void* user) {
	if (n == NULL) return;

	STACK s;
	stInit(&s);

	stPush(&s, &n, sizeof(BT_NODE*));

	while (!stIsEmpty(&s)) {
		BT_NODE* n = *(BT_NODE**)stTop(&s);
		stPop(&s);

		func(n, user);
		if (n->right != NULL) stPush(&s, &n->right, sizeof(BT_NODE*));
		if (n->left != NULL) stPush(&s, &n->left, sizeof(BT_NODE*));
	}

	stDestroy(&s);
}


void btTraverseDFSIterativeLRV(BT_NODE* n, void (*func)(BT_NODE*, void*), void* user) {
	if (n == NULL) return;

	STACK s;
	stInit(&s);

	for (;;) {
		for (; n != NULL; n = n->left) {
			stPush(&s, &n, sizeof(BT_NODE*));
			stPush(&s, &n, sizeof(BT_NODE*));
		}
		if (stIsEmpty(&s)) break;

		n = *(BT_NODE**)stTop(&s);
		stPop(&s);

		if (!stIsEmpty(&s) && *(BT_NODE**)stTop(&s) == n)
			n = n->right;
		else {
			func(n, user);
			n = NULL;
		}
	}

	stDestroy(&s);
}


void btTraverseBFS(BT_NODE* n, void (*func)(BT_NODE*, void*), void* user) {
	if (n == NULL) return;

	QUEUE q;
	qInit(&q);

	qEnqueue(&q, &n, sizeof(BT_NODE*));

	while (!qIsEmpty(&q)) {
		BT_NODE* n = *(BT_NODE**)qHead(&q);
		qDequeue(&q);

		func(n, user);
		if (n->left != NULL) qEnqueue(&q, &n->left, sizeof(BT_NODE*));
		if (n->right != NULL) qEnqueue(&q, &n->right, sizeof(BT_NODE*));
	}

	qDestroy(&q);
}


void _printTree(BT_NODE* n, char* s, int l) {
	if (n->left != NULL) {
		printf("%s%s%c\n", s, n->right == NULL ? "`--" : "|--", n->left->data);
		strcpy(s + l, n->right != NULL ? "|  " : "   ");
		_printTree(n->left, s, l+3);
		s[l] = 0;
	}

	if (n->right != NULL) {
		printf("%s`--%c\n", s, n->right->data);
		strcpy(s + l, "   ");
		_printTree(n->right, s, l+3);
		s[l] = 0;
	}
}

void btPrintTree(BT_NODE* n) {
	if (n == NULL) return;

	char s[100] = "";
	printf("%c\n", n->data);
	_printTree(n, s, 0);
}

void btPrintList(BT_NODE* n) {
	if (n == NULL) return;

	printf("(%c,[", n->data);
	btPrintList(n->left);
	if (n->left != NULL && n->right != NULL) printf(",");
	btPrintList(n->right);
	printf("])");
}

