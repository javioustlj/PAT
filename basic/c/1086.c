#include<stdio.h>

int main(void)
{
	int A = 0, B = 0;
	int product = 0, result = 0;

	scanf("%u %u", &A, &B);

	result = A * B;
	while (result)
	{
		product *= 10;
		product += result % 10;
		result /= 10;
	}

	printf("%u\n", product);

	return 0;
}	
