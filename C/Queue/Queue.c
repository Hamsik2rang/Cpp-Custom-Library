#include "Queue.h"

void QueueInit(Queue* q)
{
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

bool_t QueueIsEmpty(Queue* q)
{
	if (q->size == 0)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* q, data_t data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
	}
	if (QueueIsEmpty(q))
	{
		q->front = newNode;
		q->rear = newNode;
	}
	q->rear->next = newNode;
	q->rear = q->rear->next;
	q->size++;
}

data_t Dequeue(Queue* q)
{
	if (QueueIsEmpty(q))
	{
		printf("큐가 비었습니다.\n");
		assert(!QueueIsEmpty(q));
	}

	data_t returnData = q->front->data;
	Node* temp = q->front;
	q->front = q->front->next;
	q->size--;
	free(temp);

	return returnData;
}

data_t QueuePeek(Queue* q)
{
	return q->front->data;
}