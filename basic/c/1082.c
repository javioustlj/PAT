#include<stdio.h>

int main(void)
{
	int n = 0;
	int max = 0, min = 0;
	int max_number = 0, min_number = 0;
	int number = 0, x = 0, y = 0;

	scanf("%d", &n);

	min = 100 * 100;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &number, &x, &y);
		if (x * x + y * y > max)
		{
			max = x * x + y * y;
			max_number = number;
		}
		if (x * x + y * y < min)
		{
			min = x * x + y * y;
			min_number = number;
		}
	}

	printf("%04d %04d", min_number, max_number);

	return 0;
}
