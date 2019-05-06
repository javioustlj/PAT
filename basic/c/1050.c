#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compare_number(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}
int main(void)
{
	int N = 0;
	int m = 0, n = 0;
	int seq[100000] = {0};
	int a[1000][100] = {0};
	int i = 0, j = 0, k = 0;
	int i_upboard = 0, i_downboard = 0, j_upboard = 0, j_downboard = 0;

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &seq[i]);
	qsort(seq, N, sizeof(int), compare_number);
	for (int i = 1; i <= sqrt(N) ; i++)
	{
		if (!(N % i))
		{
			n = i;
		}
	}
	m = N / n;
	i = j = k = 0;
	i_upboard = m - 1;
	i_downboard = 0;
	j_upboard = n - 1;
	j_downboard = 0;
	a[0][0] = seq[0];
	while (k < N - 1)
	{
		while (j < j_upboard && k < N - 1)
			a[i][++j] = seq[++k];
		++i_downboard;
		while (i < i_upboard && k < N - 1)
			a[++i][j] = seq[++k];
		--j_upboard;
		while (j > j_downboard && k < N - 1)
			a[i][--j] = seq[++k];
		--i_upboard;
		while (i > i_downboard && k < N - 1)
			a[--i][j] = seq[++k];
		++j_downboard;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", a[i][j]);
			if (j < n - 1)
				printf(" ");
		}
		printf("\n");
	}



	return 0;
}

	
