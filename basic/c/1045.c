#include<stdio.h>
#include<stdlib.h>

#define N 100000

int compare_number(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(void)
{
	int n = 0, max = 0, number = 0;
	int sequence[N] = {0};
	int sorted_sequence[N] = {0};
	int result_sequence[N] = {0};

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &sequence[i]);
		sorted_sequence[i] = sequence[i];
	}
	qsort(sorted_sequence, n, sizeof(int), compare_number);

	for (int j = 0; j < n; j++)
	{
		if (max < sequence[j])
			max = sequence[j];
		if (sorted_sequence[j] == sequence[j] && max == sequence[j])
		{
			result_sequence[number++] = sequence[j];
		}
	}

	printf("%d\n", number);

	for (int i = 0; i < number; i++)
	{
		if (!i)
			printf("%d", result_sequence[i]);
		else
			printf(" %d", result_sequence[i]);
	}
	printf("\n");

	return 0;
}
