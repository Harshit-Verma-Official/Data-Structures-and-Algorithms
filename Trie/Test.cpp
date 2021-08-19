#include <stdio.h>

#define MAX 10

void enqueue(int *, int, int *, int *);
int dequeue(int *, int *, int *);
void traverse(int *);

int main()
{
	int arr[MAX];
	int front, rear, i, n;

	front = rear = -1;
	for (i = 0; i < MAX; i++)
		arr[i] = 0;

	enqueue(arr, 5, &front, &rear);
	enqueue(arr, 11, &front, &rear);
	enqueue(arr, 6, &front, &rear);

	printf("\nElements in a deque: ");
	traverse(arr);
}

void enqueue(int *arr, int item, int *pfront, int *prear)
{
	int i, k;

	if (*pfront == 0 && *prear == MAX - 1)
	{
		printf("\nDeque is full.\n");
		return;
	}

	if (*pfront == -1)
	{
		*prear = *pfront = 0;
		arr[*prear] = item;
		return;
	}

	if (*prear == MAX - 1)
	{
		k = *pfront - 1;
		for (i = *pfront - 1; i < *prear; i++)
		{
			k = i;
			if (k == MAX - 1)
				arr[k] = 0;
			else
				arr[k] = arr[i + 1];
		}
		(*prear)--;
		(*pfront)--;
	}
	(*prear)++;
	arr[*prear] = item;
}

int dequeue(int *arr, int *pfront, int *prear)
{
	int item;

	if (*pfront == -1)
	{
		printf("\nDeque is empty.\n");
		return 0;
	}

	item = arr[*pfront];
	arr[*pfront] = 0;

	if (*pfront == *prear)
		*pfront = *prear = -1;
	else
		(*pfront)++;

	return item;
}

void traverse(int *arr)
{
	printf("\n front:  ");
	for (int i = 0; i < MAX; i++)
		printf("  %d", arr[i]);
	printf("  :rear");
}

int count(int *arr)
{
	int c = 0, i;

	for (i = 0; i < MAX; i++)
	{
		if (arr[i] != 0)
			c++;
	}
	return c;
}