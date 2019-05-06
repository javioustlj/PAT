#include<stdio.h>
#include<stdlib.h>

#define N 100000

int compare_number(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(void)
{
	int n = 0;
	int seq[N] = {0};
	int E = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &seq[i]);
	
	qsort(seq, n, sizeof(int), compare_number);

	for (int i = n; i > 0; i--)
	{
		if (seq[n - i] > i)
		{
			E = i;
			break;
		}
	}
	printf("%d\n", E);

	return 0;
}
