#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool is_palindromic(char *str)
{
	int len = strlen(str);
	bool flag = true;

	for (int i = 0; i < len / 2; ++i)
	{
		if (str[i] != str[len - 1 - i])
		{
			flag = false;
			break;
		}
	}

	return flag;

}
void get_reversal_string(char *str, char *reversal)
{
	int len = strlen(str);

	for (int i = 0; i < len; ++i)
	{
		reversal[i] = str[len - 1 -i];
	}

	reversal[len] = '\0';

	return;
}
void reversal_string(char *str)
{
	char temp;
	int len = strlen(str);

	for (int i = 0; i < len / 2; ++i)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}

	return;
}
void add(char *str, char*res)
{
	int carry = 0;
	int len = strlen(str);
	
	for (int i = 0; i < len; ++i)
	{
		res[i] = str[i] + str[len - 1 - i] - '0' + carry;
		if (res[i] > '9')
		{
			res[i] -= 10;
			carry = 1;
		}
		else
			carry = 0;
	}

	if (carry)
	{
		res[len] = '0' + 1;
		res[len + 1] = '\0';
	}
	reversal_string(res);

	return;
}
int main(void)
{
	char seq[1011] = {0};
	char res[1011] = {0};
	char reversal[1011] = {0};

	scanf("%s", seq);

	if (is_palindromic(seq))
	{
		printf("%s is a palindromic number.\n", seq);
		return 0;
	}

	for (int i = 0; i < 10; ++i)
	{
		add(seq, res);
		get_reversal_string(seq, reversal);
		printf("%s + %s = %s\n", seq, reversal, res);
		if (is_palindromic(res))
		{
			printf("%s is a palindromic number.\n", res);
			return 0;
		}
		memset(seq, 0, 1011);
		strcpy(seq, res);
		memset(res, 0, 1011);
		memset(reversal, 0, 1011);
	}
	printf("Not found in 10 iterations.\n");

	return 0;
}
