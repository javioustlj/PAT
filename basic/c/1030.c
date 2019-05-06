#include<stdio.h>
#include<stdlib.h>

#define N 100000

int compare_number(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(void)
{
	int n = 0, p = 0;
	int sequence[N] = {0};
	int number = 1;

	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &sequence[i]);
	}
	qsort(sequence, n, sizeof(int), compare_number);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = number + i; j < n; j++)
		{
			if ((long long int)sequence[i] * p >= sequence[j])
				number = j - i + 1;
			else
				break;
		}
	}
	printf("%d\n", number);
	
	return 0;
}	
