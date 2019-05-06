#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define N 1001

void compress(char *str)
{
	int i = 0;
	int count = 1;
	int len = 0;

	len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == str[i + 1])
			++count;
		else
		{
			if (count > 1)
				printf("%d", count, str[i]);
			printf("%c", str[i]);
			count = 1;
		}
	}
	printf("\n");

	return;
}

void decompress(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i] != '\0')
	{
		if (isdigit(str[i]))
			count = count * 10 + str[i] - '0';
		else
		{
			for (int j = 0; j < count; ++j)
				printf("%c", str[i]);
			if (!count)
				printf("%c", str[i]);
			count = 0;
		}
		++i;
	}
	printf("\n");

	return;
}
int main(void)
{
	char flag = 0;
	char str[N] = {0};

	scanf("%c", &flag);
	getchar();
	gets(str);
	if (flag == 'C')
		compress(str);
	else if (flag == 'D')
		decompress(str);

	return 0;
}
