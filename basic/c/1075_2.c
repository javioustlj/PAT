#include<stdio.h>

#define N 100000

typedef struct node
{
	int data;
	int next;
}node;

int main(void)
{
	int n = 0, k = 0, head = 0;
	int address = -1;
	int negative_data[N] = {0};
	int mid_data[N] = {0};
	int top_data[N] = {0};
	int negative_count = 0, mid_count = 0, top_count = 0;

	node list[N] = {0};

	scanf("%d %d %d", &head, &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &address);
		scanf("%d %d", &list[address].data, &list[address].next);
	}

	address = head;

	while(address != -1)
	{
		if (list[address].data < 0)
		{
			negative_count++;
			negative_data[negative_count - 1] = address;
		}
		else if (list[address].data >= 0 && list[address].data <= k)
		{
			mid_count++;
			mid_data[mid_count - 1] = address;
		}
		else
		{
			top_count++;
			top_data[top_count - 1] = address;
		}
		address = list[address].next;
	}

	for (int i = 0; i < negative_count - 1; i++)
	{
		printf("%05d ", negative_data[i]);
		printf("%d ", list[negative_data[i]].data);
		printf("%05d\n", negative_data[i + 1]);
	}
	if (negative_count > 0)
	{
 
		printf("%05d ", negative_data[negative_count - 1]);
		printf("%d ", list[negative_data[negative_count - 1]].data);
		if (mid_count > 0)
		{

			printf("%05d\n", mid_data[0]);
		}
		else if (top_count > 0)
		{
			printf("%05d\n", top_data[0]);
		}
		else
		{
			printf("%d\n", -1);
		}
	}

	for (int i = 0; i < mid_count - 1; i++)
	{
		printf("%05d ", mid_data[i]);
		printf("%d ", list[mid_data[i]].data);
		printf("%05d\n", mid_data[i + 1]);
	}
	if (mid_count > 0)
	{
		printf("%05d ", mid_data[mid_count - 1]);
		printf("%d ", list[mid_data[mid_count - 1]].data);
		if (top_count == 0)
		{
			printf("%d\n", -1);
		}
		else
		{
			printf("%05d\n", top_data[0]);
		}

	}
	for (int i = 0; i < top_count - 1; i++)
	{
		printf("%05d ", top_data[i]);
		printf("%d ", list[top_data[i]].data);
		printf("%05d\n", top_data[i + 1]);
	}
	if (top_count > 0)
	{
		printf("%05d ", top_data[top_count - 1]);
		printf("%d ", list[top_data[top_count - 1]].data);
		printf("%d\n", -1);
	}

	return 0;
}
