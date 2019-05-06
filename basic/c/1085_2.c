#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define N 100000
typedef struct school_node
{
	char schoolID[8];
	unsigned int count;
	unsigned int sum_score;
	unsigned int score_b;
	unsigned int score_a;
	unsigned int score_t;
}school_node;

void tolower_string(char *str)
{
	while(*str != '\0')
	{
		*str = tolower(*str);
		str++;
	}

	return;
}

int compare_schoolID(const void *a, const void *b)
{
	school_node *school_a = (school_node *)a;
	school_node *school_b = (school_node *)b;

	return strcmp(school_a->schoolID, school_b->schoolID);
}

int compare_school(const void *a, const void *b)
{
	school_node *school_1 = (school_node *)a;
	school_node *school_2 = (school_node *)b;
	int flag = 0;

	if (school_1->sum_score < school_2->sum_score)
	{
		flag = 1;
	}
	else if (school_1->sum_score == school_2->sum_score)
	{
		if(school_1->count < school_2->count)
		{
			flag = -1;
		}
		else if(school_1->count == school_2->count)
		{
			flag = strncmp(school_1->schoolID, school_2->schoolID, 6);
		}
		else
		{
			flag = 1;
		}
	}
	else
	{
		flag = -1;
	}

	return flag;
}

void get_real_score(char leval, unsigned int score, school_node *school)
{
	switch(leval)
	{
		case 'B':
			school->score_b = score;
			break;
		case 'A':
			school->score_a = score;
			break;
		case 'T':
			school->score_t = score;
			break;
		default:
			break;
	}

	return;
}

void print_school(unsigned int school_count, school_node *school)
{
	unsigned int number = 1;

	printf("%u\n", school_count);	
	for(unsigned int i = 0; i < school_count; i++)
	{
		if(i > 0)
		{
			if (school[i].sum_score < school[i - 1].sum_score)
			{
				number = i + 1;
			}
		}
		printf("%u %s %u %u\n", number, school[i].schoolID, school[i].sum_score, school[i].count);
	}

	return;
}

unsigned int get_input(school_node *school)
{
	unsigned int n = 0;
	unsigned int score = 0;
	char schoolID[8] = {0};
	char studentID[8] = {0};
	
	scanf("%u", &n);
	for(unsigned int i = 0; i < n; ++i)
	{
		scanf("%s %u %s", studentID, &score, schoolID);
		tolower_string(schoolID);
		get_real_score(studentID[0], score, &school[i]);
		memcpy(school[i].schoolID, schoolID, 6u);
		school[i].count = 1;
	}

	return n;
}

unsigned int merge_school_with_same_schoolID(unsigned int n, school_node *school)
{
	unsigned int school_count = 0;
	
	qsort(school, n, sizeof(school_node), compare_schoolID);
	school_count = 1;
	for (unsigned int i = 1; i < n; i++)
	{
		if (0 == strcmp(school[school_count - 1].schoolID, school[i].schoolID))
		{
			school[school_count - 1].score_a += school[i].score_a;
			school[school_count - 1].score_b += school[i].score_b;
			school[school_count - 1].score_t += school[i].score_t;
			school[school_count - 1].count +=1;
		}
		else
		{
			school_count++;
			school[school_count - 1] = school[i];
		}
	}
	for (unsigned int i = 0; i < school_count; i++)
	{
		school[i].sum_score = (int)(school[i].score_b / 1.5 + school[i].score_a + school[i].score_t * 1.5);
	}

	return school_count;
}

int main(void)
{
	unsigned int n = 0;
	unsigned int school_count = 0;

        school_node school[N] = {0};	

	n = get_input(school);

	school_count = merge_school_with_same_schoolID(n, school);

	qsort(school, school_count, sizeof(school_node), compare_school);
	print_school(school_count, school);

	return 0;
}
