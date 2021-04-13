#include <stdio.h>
#include "Queue.h"

int main()
{
	Queue q;

	QueueInit(&q);

	Enqueue(&q, 11);
	Enqueue(&q, 22);
	Enqueue(&q, 33);
	Enqueue(&q, 55);
	Enqueue(&q, 44);

	printf("Front : %d\n", QueuePeek(&q));

	while (!QueueIsEmpty(&q))
	{
		printf("%d ", Dequeue(&q));
	}

	return 0;
}