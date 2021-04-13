#pragma once

#define LIST_LEN 100
#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _list
{
	LData container[LIST_LEN];
	int size;
	int curPtr;
} ArrayList;

typedef ArrayList List;

void ListInit(List* list);
void LInsert(List* list, LData data);
int LFirst(List* list, LData* data);
int LNext(List* list, LData* data);
LData LRemove(List* list);
int LCount(List* list);
