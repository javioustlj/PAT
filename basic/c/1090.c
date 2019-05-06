#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define N 10000
#define M 100
#define K 1000

typedef struct incompatible_items
{
	char item1[8];
	char item2[8];
}incompatible_items;

incompatible_items incompatible_item_list[N] = {0};

int compare_incompatible_items(const void *a, const void *b)
{
	incompatible_items *item_a = (incompatible_items *)a;
	incompatible_items *item_b = (incompatible_items *)b;
	int flag = 0;

	flag = strcmp(item_a->item1, item_b->item1);

	if (flag == 0)
		flag = strcmp(item_a->item2, item_b->item2);

	return flag;
}
int compare_item(const void *a, const void *b)
{
	char *item_a = (char *)a;
	char *item_b = (char *)b;

	return (strcmp(item_a, item_b));
}
bool is_item_list_compatible(unsigned int n, unsigned int k, char item_list[K][8])
{
	bool result = true;
	char *item;

	for (unsigned int i = 0; i < n; i++)
	{
		item = (char *)bsearch(incompatible_item_list[i].item1, item_list, k, 8u, compare_item);
		if (NULL != item)
		{
			item = bsearch(incompatible_item_list[i].item2, item_list, k, 8u, compare_item);
			if (NULL != item)
			{
				result = false;
				break;
			}
		}
	}	

	return result;
}
int main(void)
{
	unsigned int n = 0, m = 0, k = 0;
	char item_list[K][8] = {0};
	bool result[M] = {false};

	scanf("%u %u", &n, &m);

	for (unsigned int i = 0; i < n; i++)
	{
		scanf("%s %s", incompatible_item_list[i].item1, incompatible_item_list[i].item2);
	}
	
	qsort(incompatible_item_list, n, sizeof(incompatible_items), compare_incompatible_items);
	for (unsigned int i = 0; i < m; i++)
	{
		scanf("%u", &k);
		for (unsigned int i = 0; i < k; i++)
		{
			scanf("%s", item_list[i]);
		}
		qsort(item_list, k, 8, compare_item);
		result[i] = is_item_list_compatible(n, k, item_list);
	}

	for (unsigned int i = 0; i < m; i++)
	{
		if (result[i] == true)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
