#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define N 100

typedef enum status
{
	wanmei,
	duan,
	luan,
	needshuzi,
	needzimu
}status;

status get_status(char *str)
{
	int flag_alp = 0, flag_num = 0;
	int i = 0;

	if (strlen(str) < 6)
		return duan;

	while (str[i] != '\0')
	{
		if (!isalnum(str[i]) && str[i] != '.')
				return luan;
		++i;
	}

	i = 0;
	while (str[i] != '\0')
	{
		if (isalpha(str[i]))
			flag_alp = 1;
		if (str[i] >= '0' && str[i] <= '9')
			flag_num = 1;
		++i;
	}

	if (!flag_num)
		return needshuzi;
	if (!flag_alp)
		return needzimu;
	return wanmei;
}

		

int main(void)
{
	int n = 0;
	char pass[N][81];
	status res = wanmei;
	char output[5][32] = {
		"Your password is wan mei.",
		"Your password is tai duan le.",
		"Your password is tai luan le.",
		"Your password needs shu zi.",
		"Your password needs zi mu."
	};

	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; ++i)
		gets(pass[i]);

	for (int i = 0; i < n; ++i)
	{
		res = get_status(pass[i]);
		printf("%s\n", output[res]);
	}	

	return 0;
}
