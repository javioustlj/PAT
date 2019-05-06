#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 1000
#define D 500

typedef struct moon_cake_node
{
	float amount;
	float total_price;
}moon_cake_node;

int compare_moon_cake(const void *a, const void *b)
{
	int flag = 0;
	float res = 0;
	moon_cake_node *cake_a = (moon_cake_node *)a;
	moon_cake_node *cake_b = (moon_cake_node *)b;
	
	res = cake_a->total_price / cake_a->amount - cake_b->total_price / cake_b->amount;
	if (res > 0)
		flag = -1;
	else if (res == 0)
		flag = 0;
	else
		flag = 1;
	return flag;
}
int main(void)
{
	int n = 0, d = 0;
	float revenue = 0;
	float sum_amount = 0;
	moon_cake_node moon_cake[N] = {0};

	scanf("%d %d", &n, &d);

	for (int i = 0; i < n; ++i)
		scanf("%f", &moon_cake[i].amount);
	for (int i = 0; i < n; ++i)
		scanf("%f", &moon_cake[i].total_price);

	qsort(moon_cake, n, sizeof(moon_cake_node), compare_moon_cake);

	for (int i = 0; i < n; ++i)
	{
		if (sum_amount + moon_cake[i].amount < d)
		{
			sum_amount += moon_cake[i].amount;
			revenue += moon_cake[i].total_price;
		}
		else
		{
			revenue += (d - sum_amount) * moon_cake[i].total_price / moon_cake[i].amount;
			break;
		}
	}
	revenue = (float)floor(revenue * 100 + 0.5) / 100.0;

	printf("%.2f\n", revenue);

	return 0;
}
