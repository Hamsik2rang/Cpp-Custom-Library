#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int bool_t;
typedef int data_t;

typedef struct _node
{
	data_t data;
	struct _node* next;
}Node;

typedef struct _queue
{
	Node* front;
	Node* rear;
	int size;
}Queue;

void QueueInit(Queue* q);
bool_t QueueIsEmpty(Queue* q);
void Enqueue(Queue* q, data_t data);
data_t Dequeue(Queue* q);
data_t QueuePeek(Queue* q);