#include<stdio.h>

#define N 101

int main(void)
{
	int n = 0, k = 0;
	char str[4] = {0};
	char ans[N] = {0};

	scanf("%d", &n);

	for (int i = 0; i < 4 * n; ++i)
	{
		scanf("%s", str);
		if (str[2] == 'T')
			ans[k++] = str[0] - 'A' + 1 + '0';
	}
	ans[k] = '\0';
	printf("%s\n", ans);

	return 0;
}
