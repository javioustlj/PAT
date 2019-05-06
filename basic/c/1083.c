#include<stdio.h>
#include<stdlib.h>

#define N 10000

int compare_number(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}
int main(void)
{
	int n = 0, count = 0;
	int seq[N] = {0};

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);

	for (int i = 0; i < n; ++i)
		seq[i] = abs(seq[i] - i - 1);
	qsort(seq, n, sizeof(int), compare_number);

	count = 1;
	for (int i = 1; i < n; ++i)
	{
		if (seq[i] == seq[i - 1])
			++count;
		else
		{
			if (count > 1)
				printf("%d %d\n", seq[i - 1], count);
			count = 1;
		}
	}
	if (count > 1)
		printf("%d %d\n", seq[n - 1], count);

	return 0;
}
