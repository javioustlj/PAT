#include<stdio.h>

int main(void)
{
	int a = 0, n = 0;

	scanf("%d %d", &a, &n);
	if (n)
		printf("%d %d", a * n, n - 1);
	else
	{
		printf("%d %d", 0, 0);
		return 0;
	}
	while (EOF != scanf("%d %d", &a, &n))
		if (n)
			printf(" %d %d", a * n, n - 1);

	return 0;
}
