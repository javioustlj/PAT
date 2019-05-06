#include<stdio.h>
#include<string.h>

#define N 100000

typedef struct node
{
	int data;
	char address[6];
	char next[6];
}node;
	
int main(void)
{
	char head[8] = {0};
	int n = 0, k = 0;
	node list[N] = {0};
	node new_list[N] = {0};
	node temp = {0};
	int negative_count = 0;
	int mid_count = 0;
	int top_count = 0;

	scanf("%s %d %d", head, &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%s %d %s", list[i].address, &list[i].data, list[i].next);
	}

	for (int i = 0; i < n; i++)
	{
		if (strcmp(head, list[i].address) == 0)
		{
			temp = list[0];
			list[0] = list[i];
			list[i] = temp;
			break;
		}
	}	

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(list[i].next, list[j].address) == 0)
			{
				temp = list[i + 1];
				list[i + 1] = list[j];
				list[j] = temp;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (list[i].data < 0)
		{
			negative_count++;
			new_list[negative_count - 1] = list[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (list[i].data >= 0 && list[i].data <= k)
		{
			mid_count++;
			new_list[negative_count + mid_count - 1] = list[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (list[i].data > k)
		{
			top_count++;
			new_list[negative_count + mid_count + top_count - 1] = list[i];
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		strncpy(new_list[i].next, new_list[i + 1].address, 6);
	}

	strcpy(new_list[n - 1].next, "-1");
	for(int i = 0; i < n - 1; i++)
	{
		printf("%s %d %s\n", new_list[i].address, new_list[i].data, new_list[i].next);
	}
	printf("%s %d %s\n", new_list[n - 1].address, new_list[n - 1].data, "-1");

	return 0;
}
