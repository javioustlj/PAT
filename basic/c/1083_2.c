#include<stdio.h>
#include<stdlib.h>

#define N 10000

int main(void)
{
	int n = 0, count = 0;
	int seq[N] = {0};
	int diff[N] = {0};

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);

	for (int i = 0; i < n; ++i)
	{
		seq[i] = abs(seq[i] - i - 1);
		++diff[seq[i]];
	}
	for (int i = N - 1; i >= 0; --i)
		if (diff[i] > 1)
			printf("%d %d\n", i, diff[i]);

	return 0;
}
