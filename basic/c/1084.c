#include<stdio.h>

int main(void)
{
	int d = 0, n = 0, k = 0, count = 0;
	int int_num = 0, temp = 0;
	int seq[2][1000] = {0};

	scanf("%d %d", &d, &n);

	seq[0][0] = d;
	int_num = 1;
	for (int i = 0; i < n - 1; ++i)
	{
		k = 0;
		temp = seq[i % 2][0];
		count = 1;
		seq[(i + 1) % 2][0] = seq[i % 2][0];
		for (int j = 1; j < int_num; ++j)
		{
			if (seq[i % 2][j] == temp)
			{
				++count;
			}
			else
			{
				seq[(i + 1) % 2][++k] = count;
				seq[(i + 1) % 2][++k] = seq[i % 2][j];
				temp = seq[i % 2][j];
				count = 1;
			}
		}
		seq[(i + 1) % 2][++k] = count;
		int_num = k + 1;
		for (int j = 0; j < 1000; ++j)
			seq[i % 2][j] = 0;
	}

	for (int i = 0; i < int_num; ++i)
		printf("%d", seq[(n + 1) % 2][i]);

	printf("\n");

	return 0;
}

