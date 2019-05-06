#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10000
#define K 10

typedef struct person_node
{
	int height;
	char name[9];
}person_node;

int compare_person(const void *a, const void *b)
{
	int flag = 0;

	person_node *person_a = (person_node *)a;
	person_node *person_b = (person_node *)b;

	flag = person_b->height - person_a->height;

	if (!flag)
		flag = strcmp(person_a->name, person_b->name);

	return flag;
}

int main(void)
{
	int n = 0, k = 0;
	int num = 0; // 每队人数
	person_node people[N] = {0};
	person_node *person = people;

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%s %d", person[i].name, &person[i].height);

	qsort(person, n, sizeof(person_node), compare_person);

	for (int j = 0; j < k; j++)
	{
		if (!j)
			num = n / k + n % k;
		else
			num = n / k;
		for (int i = 0; i < num; i++)
		{
			if (i < num / 2)
			{
				printf("%s", person[num - 1 - num % 2 - 2 * i].name);
			}
			else if (i == num / 2)
			{
				printf("%s", person[0].name);
			}
			else
			{
				printf("%s", person[(i - num / 2) * 2].name);
			}
			if (i < num - 1)
				putchar(' ');
		}
		putchar('\n');
		person += num;
	}

	return 0;
}

