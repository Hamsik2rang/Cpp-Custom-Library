#include "Stack.h"

void StackInit(Stack* stk)
{
	stk->top = NULL;
	stk->size = 0;
}

bool_t StackIsEmpty(Stack* stk)
{
	if (stk->size > 0)
		return FALSE;
	else
		return TRUE;
}

void StackPush(Stack* stk, data_t data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = stk->top;
		stk->top = newNode;
	}
	stk->size++;
}

data_t StackPop(Stack* stk)
{
	data_t returnData = stk->top->data;
	Node* temp = stk->top;
	stk->top = stk->top->next;
	stk->size--;
	free(temp);

	return returnData;
}

data_t StackPeek(Stack* stk)
{
	return stk->top->data;
}

int StackSize(Stack* stk)
{
	return stk->size;
}