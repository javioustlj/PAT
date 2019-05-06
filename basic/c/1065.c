#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 50000
#define M 10000

int compare_number(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main(void)
{
	int n = 0, m = 0;
	int c1 = -1, c2 = -1;
	int couple[2 * N] = {0};
	int guest[M] = {0};
	int single[M] = {0};
	int *item = NULL;
	int number = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		couple[i] = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &c1, &c2);
		couple[c1] = c2;
		couple[c2] = c1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &guest[i]);

	qsort(guest, m, sizeof(int), compare_number);
	for (int i = 0; i < m; i++)
	{
		item = (int *)bsearch(&couple[guest[i]], guest, m, sizeof(int), compare_number);
		if (NULL == item)
		{
			single[number++] = guest[i];
		}
	}

	qsort(single, number, sizeof(int), compare_number);
	printf("%d\n", number);
	for (int i = 0; i < number; i++)
	{
		printf("%05d", single[i]);
		if (i < number - 1)
			printf(" ");
	}
	
	return 0;
}
