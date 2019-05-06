#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[100004] = {0};
	int n = 0;
	int T_count = 0, P_count = 0;
	long long int ans = 0;

	scanf("%s", str);
	
	n = strlen(str);

	for (int i = 0; i < n; i++)
		if (str[i] == 'T')
			++T_count;
	for (int i = 0; i < n; ++i)
	{
		switch (str[i])
		{
			case 'P':
				++P_count;
				break;
			case 'A':
				ans += (long long int)P_count * T_count;
				break;
			case 'T':
				--T_count;
				break;
			default:
				break;
		}
	}

	printf("%lld", ans % 1000000007);

	return 0;
}
