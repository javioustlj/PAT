#include<stdio.h>
#include<math.h>
#include<stdbool.h>

#define N 100

int get_input(int *statement)
{
	int n = 0;

	scanf("%u", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &statement[i]);
	}

	return n;
}

int main(void)
{
	int n = 0;
	int statement[N] = {0};
	int lie_number = 0, wolf_lie_number = 0;

	n = get_input(statement);

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			lie_number = 0;
			wolf_lie_number = 0;
			for (int k = 0; k < n; k ++)
			{
				if (statement[k] == i + 1 || statement[k] == j + 1)
				{
					lie_number++;
					if (k == i || k == j)
					{
						wolf_lie_number++;
					}
				}
				else if (statement[k] < 0 && statement[k] != -1 * (i + 1) && statement[k] != -1 * (j + 1))
				{
					lie_number++;
					if ( k == i || k == j)
					{
						wolf_lie_number++;
					}
				}
			}
			if (lie_number == 2 && wolf_lie_number == 1)
			{
				printf("%d %d\n", i + 1, j + 1);
				return 0;
			}

		}
	}

	printf("No Solution\n");

	return 0;
}
