#include<stdio.h>
#include<string.h>

#define N 21

void remove_zero(char *str)
{
	int len = strlen(str);
	char temp[N] = {0};
	strcpy(temp, str);

	for (int i = 0; i < len; ++i)
	{
		if (temp[i] != '0')
		{
			strcpy(str, &temp[i]);
			return;
		}
	}

	str[0] = '0';
	str[1] = '\0';

	return;
}
void reverse(char *str)
{
	char c = 0;
	int len = strlen(str);

	for (int i = 0; i < len / 2; ++i)
	{
		c = str[len - 1 - i];
		str[len - 1 - i] = str[i];
		str[i] = c;
	}

	return;
}

int main(void)
{
	char table[N] = {0};
	char n1[N] = {0};
	char n2[N] = {0};
	char ans[N + 1] = {0};
	int carry = 0;
	int i = 0, j = 0, k = 0, m = 0;
	int len1 = 0, len2 = 0, len_t = 0;

	scanf("%s", table);
	scanf("%s", n1);
	scanf("%s", n2);

	remove_zero(n1);
	remove_zero(n2);

	len_t = strlen(table);
	len1 = strlen(n1);
	len2 = strlen(n2);

	i = len1 - 1;
	j = len2 - 1;
	k = 0;
	m = len_t - 1;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
			ans[k] += n1[i] - '0';
		if (j >= 0)
			ans[k] += n2[j] - '0';
		ans[k] += carry;
		if (table[m] == '0')
			table[m] = '0' + 10;
		if (ans[k] >= table[m] - '0')
		{
			ans[k] -= table[m] - '0';
			carry = 1;
		}
		else
			carry = 0;
		ans[k] += '0';
		--i;
		--j;
		++k;
		--m;
	}
	if (carry > 0)
		ans[k++] = '1';
	ans[k] = '\0';
	reverse(ans);

	printf("%s\n", ans);

	return 0;
}
