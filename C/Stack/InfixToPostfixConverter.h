#pragma once
#include <string.h>
#include "Stack.h"

#define MAX_EXPR_LEN 256
#define TRUE 1
#define FALSE 0

typedef int bool_t;

int Calculate(const char infixExpression[]);