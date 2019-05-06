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
	bool result = false;
	int n = 0;
	int statement[N] = {0};
	int wolf_people[2] = {0};
	int solution[2] = {0};

	n = get_input(statement);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				for (int k = 0; k < n; k++)
				{
					if (k != i && k != j)
					{
						statement[i] = -1 * statement[i];
						statement[k] = -1 * statement[k];
						result = true;
						for (int m = 0; m < n; m++)
						{
							if ((statement[m] != -1 * (i + 1) && statement[m] != -1 * (j + 1) && statement[m] < 0) || statement[m] == i + 1 || statement[m] == j + 1)
							{
								result = false;
								break;
							}
						}
						if (result == true)
						{
							if (i > j)
							{
								wolf_people[0] = j + 1;
								wolf_people[1] = i + 1;
							}
							else
							{
								wolf_people[0] = i + 1;
								wolf_people[1] = j + 1;
							}
							if (solution[0] == 0)
							{
								solution[0] = wolf_people[0];
								solution[1] = wolf_people[1];
							}
							if (solution[1] > wolf_people[1])
							{
								solution[1] = wolf_people[1];
								solution[0] = wolf_people[0];
							}
						}
						statement[i] = -1 * statement[i];
						statement[k] = -1 * statement[k];

					}
				}
			}
		}
	}
	if (solution[0] != 0)
	{
		printf("%d %d\n", solution[0], solution[1]);
	}
	else 
	{
		printf("No Solution\n");
	}

	return 0;
}
