#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* list)
{
	list->size = 0;
	list->curPtr = 0;
}

void LInsert(List* list, LData data)
{
	if (list->size >= LIST_LEN)
	{
		printf("%s\n", "저장이 불가능합니다.");
		return;
	}
	list->container[list->curPtr++] = data;
	list->size++;
}

int LFirst(List* list, LData* data)
{
	if (list->size == 0)
		return FALSE;
	list->curPtr = 0;
	*data = list->container[list->curPtr++];
	return TRUE;
}

int LNext(List* list, LData* data)
{
	if (list->curPtr >= list->size)
		return FALSE;
	*data = list->container[list->curPtr++];
	return TRUE;
}

LData LRemove(List* list)
{
	int removePtr = list->curPtr;
	int cnt = list->size;
	LData returnData = list->container[list->curPtr - 1];

	for (int i = removePtr; i < cnt; i++)
	{
		list->container[i - 1] = list->container[i];
	}
	list->size--;
	list->curPtr--;

	return returnData;
}

int LCount(List* list)
{
	return list->size;
}