#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

#define N 100000
typedef struct school_node
{
	char schoolID[8];
	unsigned int sum_score;
	unsigned int count;
}school_node;

void tolower_string(char *str)
{
	int i = 0;	
	while(str[i] != '\0')
	{
		str[i] = tolower(str[i]);
		i++;
	}

	return;
}

unsigned int is_exist_school(char *schoolID, school_node *school, unsigned int school_count)
{
	unsigned int i = 0;
	for(i = 0; i < school_count; i++)
		if (strncmp(school[i].schoolID, schoolID, 6) == 0)
			break;

	return i;
}
int compare_school(school_node *school_1, school_node *school_2)
{
	int flag = 0;

	if (school_1->sum_score < school_2->sum_score)
	{
		flag = -1;
	}
	else if (school_1->sum_score == school_2->sum_score)
	{
		if(school_1->count < school_2->count)
		{
			flag = 1;
		}
		else if(school_1->count == school_2->count)
		{
			flag = -1 * strncmp(school_1->schoolID, school_2->schoolID, 6);
		}
		else
		{
			flag = -1;
		}
	}
	else
	{
		flag = 1;
	}

	return flag;
}

void sort_school(unsigned int school_count, school_node *school)
{
	int flag = 0;
	school_node temp_school = {0};

	for(int i = 0; i < school_count; i++)
	{
		for (int j = i + 1; j < school_count; j++)
		{
			flag = compare_school(&school[i], &school[j]);
			if(flag > 0)
			{
				temp_school = school[i];
				school[i] = school[j];
				school[j] = temp_school;
			}
		}
	}

	return;	
}

void merge_school(school_node school[], int left, int mid, int right)
{
	int len = right - left +1; 
	int i = left;
	int j = mid + 1;
	int k = 0;
	int flag = 0;
	school_node temp_school[len];

	while (i <= mid && j <= right)
	{
		flag = compare_school(&school[i], &school[j]);
		if (flag > 0)
			temp_school[k++] = school[i++];
		else 
			temp_school[k++] = school[j++];
	}
	while (i <= mid)
		temp_school[k++] = school[i++];
	while (j <= right)
		temp_school[k++] = school[j++];

	for (int i = 0; i < k; i++)
		school[left + i] = temp_school[i];
	return;
}
void merge_sort_school(school_node *school, int len) 
{
	int left, mid, right;

	if (len <= 1)
		return;
	for (int gap = 1; gap < len; gap *= 2)
	{
		left = 0;
		while (left + gap < len)
		{
			mid = left + gap -1;
			right = mid + gap < len ? mid + gap : len - 1;
			merge_school(school, left, mid, right);
			left = right + 1;
		}
	}

	return;
}

void print_school(unsigned int school_count, school_node *school)
{
	unsigned int number = 1;

	printf("%u\n", school_count);	
	for(int i = 0; i < school_count; i++)
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
void get_real_score(char leval, unsigned int *score)
{
	switch(leval)
	{
		case 'B':
			*score /= 1.5;
			break;
		case 'A':
			break;
		case 'T':
			*score *= 1.5;
			break;
		default:
			break;
	}

	return;
}

int main(void)
{
	unsigned int n = 0;
	unsigned int index = 0;
	unsigned int score = 0;
	unsigned int school_count = 0;
	char studentID[8] = {0};
	char schoolID[8] = {0};

        school_node school[N + 1] = {0};	

	scanf("%u", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%s %u %s", studentID, &score, schoolID);
		tolower_string(schoolID);
		
		index = is_exist_school(schoolID, school, school_count);
		if (index == school_count)
		{
			school_count++;
			memcpy(school[index].schoolID, schoolID, 6u);
		}
		get_real_score(studentID[0], &score);	
		school[index].sum_score += score;
		school[index].count += 1;

	}
	//sort_school(school_count, school);	
	merge_sort_school(school, school_count);
	print_school(school_count, school);

	return 0;
}
