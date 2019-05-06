#include<stdio.h>

#define N 100000

typedef struct node
{
	int data;
	int next;
}node;

int main(void)
{
	int k = 0, n = 0;
	int head = 0;
	int address = -1;
	int i = 0;
	node list[N] = {0};
	int data_address[N] = {0};
	int reverse_address[N] = {0};

	scanf("%d %d %d", &head, &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &address);
		scanf("%d %d", &list[address].data, &list[address].next);
	}

	address = head;
	while (address != -1)
	{
		data_address[i] = address;
		address = list[address].next;
		i++;
	}

	n = i; //输入中的节点并不是都有效，所以实际链表中的n就是上面统计的i
	for (i = 0; i < n - k + 1; i += k)
	{
		for (int j = 0; j < k; j++)
		{
			reverse_address[i + j] = data_address[i + k - j - 1];
		}
	}
	for (int j = n / k * k; j < n; j++)
	{
		reverse_address[j] = data_address[j];
	}

	for (int j = 0; j < n - 1; j++)
	{
		printf("%05d %d %05d\n", reverse_address[j], list[reverse_address[j]].data, reverse_address[j + 1]);
	}
	printf("%05d %d %d\n", reverse_address[n - 1], list[reverse_address[n - 1]].data, -1);

	return 0;
}
