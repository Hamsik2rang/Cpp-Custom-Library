#pragma once

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node* next;
}Node;

typedef struct _list
{
	Node* head;
	Node* cur;
	Node* before;
	int size;
}LinkedList;

typedef LinkedList List;

void ListInit(List* list);
void LInsert(List* list, LData data);
int LFirst(List* list, LData* data);
int LNext(List* list, LData* data);
LData LRemove(List* list);
int LCount(List* list);
void LSort(List* list, int (*comparer)(LData d1, LData d2));
void AllRemove(List* list);