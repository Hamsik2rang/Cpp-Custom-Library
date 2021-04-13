#pragma warning(disable:4996)
#include <stdio.h>
#include "LinkedList.h"

int Ascending(int d1, int d2)
{
	return d1 <= d2;
}

int Descending(int d1, int d2)
{
	return d1 >= d2;
}

int main()
{
	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 11);
	LInsert(&list, 33);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 11);

	printf("현재 저장된 데이터의 수 : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
	printf("\n\n");

	if (LFirst(&list, &data))
	{
		if (data == 22)
		{
			LRemove(&list);
		}
		while (LNext(&list, &data))
		{
			if (data == 22)
			{
				LRemove(&list);
			}
		}
	}

	printf("현재 데이터의 수 : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}

	printf("\n\n");
	LSort(&list, Descending);

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}

	AllRemove(&list);

	return 0;
}

