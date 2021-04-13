#pragma once
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef char data_t;
typedef int bool_t;

typedef struct _node
{
	data_t data;
	struct _node* next;
} Node;

typedef struct _stack
{
	Node* top;
	int size;
} Stack;

void StackInit(Stack* stk);
bool_t StackIsEmpty(Stack* stk);
void StackPush(Stack* stk, data_t data);
data_t StackPop(Stack* stk);
data_t StackPeek(Stack* stk);
int StackSize(Stack* stk);