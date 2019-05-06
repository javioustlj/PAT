#include<stdio.h>
#include<stdlib.h>

void print_relation(int a, int M)
{
	if (M < a)
	{
		printf("Cong");
	}
	else if (M == a)
	{
		printf("Ping");
	}
	else
	{
		printf("Gai");
	}

	return;
}
void print_result(int jia, int yi, double bing, int M)
{
	printf("%d ", jia);
	print_relation(jia, M);
	printf(" ");
	print_relation(yi, M);
	printf(" ");
	//由于丙的值可以不是整数，所以不能用上个函数
	if (M < bing)
	{
		printf("Cong");
	}
	else if (M == bing)
	{
		printf("Ping");
	}
	else
	{
		printf("Gai");
	}

	printf("\n");

	return;
}
	
int main(void)
{
	int M = 0, X = 0, Y = 0;
	int yi = 0;
	double bing;

	scanf("%d %d %d", &M, &X, &Y);

	for (int jia = 99; jia > 9; jia--)
	{
		yi = jia / 10 + jia % 10 * 10;
		bing = (double)abs(jia - yi) / (double)X;
		if (yi == bing * Y)
		{
			print_result(jia, yi, bing, M);
			return 0;
		}
	}

	printf("No Solution\n");

	return 0;
}
