#include<stdio.h>

#define N 100

int main(void)
{
	int n = 0, M = 0;
	int teacher = 0, group = 0;
	int sum = 0, count = 0;
	int max = 0, min = 0;
	int ans = 0;

	scanf("%d %d", &n, &M);

	for (int i = 0; i < n; ++i)
	{
		sum = 0;
		max = 0;
		min = M;
		count = 0;
		scanf("%d", &teacher);
		for (int j = 1; j < n; ++j)
		{
			scanf("%d", &group);
			if (group >= 0 && group <= M)
			{
				sum += group;
				++count;
				if (max < group)
					max = group;
				if (min > group)
					min = group;
			}
		}
		sum -= max + min; count -= 2;
		ans = (int)((sum / (double)count + teacher) / 2.0 + 0.5);
		printf("%d\n", ans);
	}

	return 0;
}
