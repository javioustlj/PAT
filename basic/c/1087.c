#include<stdio.h>

int main(void)
{
	int n = 0;
	int count = 1;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0)
			count++;
	}
	printf("%d\n", count);

	return 0;
		
}
