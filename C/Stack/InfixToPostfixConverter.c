#include "InfixToPostfixConverter.h"

char Evaluate(char lvalue, char op, char rvalue)
{
	lvalue -= '0';
	rvalue -= '0';
	char result = 0;
	switch (op)
	{
	case '+':
		result = lvalue + rvalue;
		break;
	case '-':
		result = lvalue - rvalue;
		break;
	case '*':
		result = lvalue * rvalue;
		break;
	case '/':
		result = lvalue / rvalue;
		break;
	default:
		break;
	}
	return result + '0';
}

int Calculate(const char infix[])
{
	Stack converter;
	size_t expSize = strlen(infix);
	char postfix[MAX_EXPR_LEN] = { 0 };
	int ptr = 0;

	StackInit(&converter);

	for (int i = 0; i < expSize; i++)
	{
		if (infix[i] >= '0' && infix[i] <= '9')
		{
			postfix[ptr++] = infix[i];
		}
		else if (infix[i] == '(')
		{
			StackPush(&converter, infix[i]);
		}
		else if (infix[i] == ')')
		{
			while (!StackIsEmpty(&converter) && StackPeek(&converter) != '(')
			{
				postfix[ptr++] = StackPop(&converter);
			}
			StackPop(&converter);
		}
		else if (infix[i] == '*' || infix[i] == '/')
		{
			while (!StackIsEmpty(&converter) && StackPeek(&converter) != '(' && StackPeek(&converter) != '+' && StackPeek(&converter) != '-')
			{
				postfix[ptr++] = StackPop(&converter);
			}
			StackPush(&converter, infix[i]);
		}
		else if (infix[i] == '+' || infix[i] == '-')
		{
			while (!StackIsEmpty(&converter) && StackPeek(&converter) != '(')
			{
				postfix[ptr++] = StackPop(&converter);
			}
			StackPush(&converter, infix[i]);
		}
	}

	while (!StackIsEmpty(&converter))
	{
		postfix[ptr++] = StackPop(&converter);
	}


	StackInit(&converter);
	size_t postExpSize = strlen(postfix);
	for (ptr = 0; ptr < postExpSize; ptr++)
	{
		if (postfix[ptr] >= '0' && postfix[ptr] <= '9')
		{
			StackPush(&converter, postfix[ptr]);
		}
		else
		{
			char rvalue = StackPop(&converter);
			char lvalue = StackPop(&converter);
			char op = postfix[ptr];

			StackPush(&converter, Evaluate(lvalue, op, rvalue));
		}
	}

	return StackPop(&converter) - '0';
}
