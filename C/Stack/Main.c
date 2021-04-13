#pragma warning(disable:4996)
#include <stdio.h>
#include "InfixToPostfixConverter.h"

int main()
{
	char infix[MAX_EXPR_LEN] = { 0 };

	scanf("%s", &infix);

	printf("%d", Calculate(infix));

	return 0;
}