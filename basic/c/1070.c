#include<stdio.h>
#include<stdlib.h>

#define N 10000

int compare_number(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(void)
{
	int n = 0;
	int seq[N] = {0};
	double ans = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	
	qsort(seq, n, sizeof(int), compare_number);	
	ans = seq[0];
	for (int i = 1; i < n; ++i)
	{
		ans = ans / 2.0 + seq[i] / 2.0;
	}

	printf("%d\n", (int)ans);

	return 0;
}
