#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STUDENT_NUMBER 10000UL
typedef struct student_node
{
	int G_p;
	int G_mid_term;
	int G_final;
	int G;
	int count;   //成绩个数，就是用来看是否有mid term成绩
	char studentID[21];
}student_node;

int compare_studentID(const void *a, const void *b)
{
	student_node *student1 = (student_node *)a;
	student_node *student2 = (student_node *)b;

	return strcmp(student1->studentID, student2->studentID);
}
int compare_student(const void *a, const void *b)
{
	int flag = 0;
	student_node *student1 = (student_node *)a;
	student_node *student2 = (student_node *)b;

	if (student1->G < student2->G)
		flag = 1;
	else if (student1->G == student2->G)
		flag = strcmp(student1->studentID, student2->studentID);
	else
		flag = -1;

	return flag;
}
int main(void)
{
	int P = 0, M = 0, N = 0;
	int student_number = 0;
	student_node student[3 * MAX_STUDENT_NUMBER] = {0};	

	scanf("%d %d %d", &P, &M, &N);

	for (int i = 0; i < P; i++)
	{
		scanf("%s %d", student[i].studentID, &student[i].G_p);
	}
	for (int i = P; i < P + M; i++)
		scanf("%s %d", student[i].studentID, &student[i].G_mid_term);
	for (int i = P + M; i < P + M + N; i++)
		scanf("%s %d", student[i].studentID, &student[i].G_final);

	qsort(student, P + M + N, sizeof(student_node), compare_studentID);

	student_number = 1;
	for (int i = 1; i < P + M + N; i++)
	{
		if (strcmp(student[student_number - 1].studentID, student[i].studentID) == 0)
		{
			student[student_number - 1].G_p += student[i].G_p;
			student[student_number - 1].G_mid_term += student[i].G_mid_term;
			student[student_number - 1].G_final += student[i].G_final;
			student[student_number - 1].count++;
		}
		else
		{
			student_number++;
			student[student_number - 1] = student[i];
		}
	}
			
	for (int i = 0; i < student_number; i++)
	{
		if (student[i].G_mid_term > student[i].G_final)
		{
			student[i].G = student[i].G_mid_term * 0.4 + student[i].G_final * 0.6 + 0.5;
		}
		else 
		{
			student[i].G = student[i].G_final;
		}
		if (student[i].count == 2 )
			student[i].G_mid_term = -1;
	}
	qsort(student, student_number, sizeof(student_node), compare_student);
	for (int i = 0; i < student_number; i++)
	{
		if (student[i].G_p >= 200 &&student[i].G_p <= 900 && student[i].G >= 60 && student[i].G <= 100)
		{
			if (student[i].G_mid_term <= 100 && student[i].G_final >= 0 && student[i].G_final <= 100)
			{
				printf("%s %d %d %d %d\n", student[i].studentID, student[i].G_p, student[i].G_mid_term, student[i].G_final, student[i].G);
			}
		}
	}

	return 0;
}
