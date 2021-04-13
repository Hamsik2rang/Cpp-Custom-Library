#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "LinkedList.h"


void ListInit(List* list)
{
	list->head = NULL;
	list->cur = NULL;
	list->before = NULL;
	list->size = 0;
}

void LInsert(List* list, LData data)
{
	if (list->head == NULL)
	{
		list->head = (Node*)malloc(sizeof(Node));
		if (list->head != NULL)
		{
			list->head->data = data;
			list->head->next = NULL;
			list->cur = list->head;
			list->cur->next = NULL;
			list->before = list->head;
		}
	}
	else if (list->cur == list->before)
	{
		list->cur->next = (Node*)malloc(sizeof(Node));
		if (list->cur->next != NULL)
		{
			list->before = list->cur;
			list->cur = list->cur->next;
			list->cur->data = data;
			list->cur->next = NULL;

		}
	}
	else
	{
		list->cur->next = (Node*)malloc(sizeof(Node));
		if (list->cur->next != NULL)
		{
			list->before = list->cur;
			list->cur = list->cur->next;
			list->cur->data = data;
			list->cur->next = NULL;
		}
	}
	list->size++;
}

int LFirst(List* list, LData* data)
{
	list->cur = list->head;
	list->before = list->head;
	if (list->cur == NULL)
	{
		return FALSE;
	}
	*data = list->cur->data;

	return TRUE;
}

int LNext(List* list, LData* data)
{
	if (list->cur->next == NULL)
	{
		return FALSE;
	}
	list->before = list->cur;
	list->cur = list->cur->next;
	*data = list->cur->data;

	return TRUE;
}

LData LRemove(List* list)
{
	LData returnData = list->cur->data;
	if (list->size == 0)
	{
		printf("삭제할 노드가 없습니다.");
	}
	list->before->next = list->cur->next;
	free(list->cur);
	list->cur = list->before;
	list->size--;

	return returnData;
}

int LCount(List* list)
{
	return list->size;
}

void LSort(List* list, int(*comparer)(LData d1, LData d2))
{
	for (int i = 0; i < list->size - 1; i++)
	{
		Node* compCur = list->head;
		Node* compNext = list->head->next;
		for (int j = 0; j < list->size - i - 1; j++, compCur = compCur->next, compNext = compNext->next)
		{
			if (!comparer(compCur->data, compNext->data))
			{
				LData temp = compCur->data;
				compCur->data = compNext->data;
				compNext->data = temp;
			}
		}
	}
}

void AllRemove(List* list)
{
	while (list->head != NULL)
	{
		Node* temp = list->head;
		list->head = list->head->next;
		free(temp);
	}
}