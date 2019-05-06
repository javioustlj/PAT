#include<stdio.h>
#include<stdlib.h>

#define N 100000

typedef struct student
{
	int number;
	int de;
	int cai;
}student;
int H = 0, L = 0;

int get_student_class(student *stu)
{
	int class = 0;

	if (stu->de >= H && stu->cai >= H)
		class = 1;
	else if (stu->de >= H && stu->cai < H && stu->cai >= L)
		class = 2;
	else if (stu->de >= L && stu -> cai >= L && stu->de >= stu->cai)
		class = 3;
	else if (stu->de >= L && stu -> cai >= L && stu->de < stu->cai)
		class = 4;
	else
		class = 5;

	return class;
}

int compare_student_class(student *stu_a, student *stu_b)
{
	return (get_student_class(stu_a) - get_student_class(stu_b));
}
	
int compare_student(const void *a, const void *b)
{
	student *stu_a = (student *)a;
	student *stu_b = (student *)b;
	int flag = 0;

	flag = compare_student_class(stu_a, stu_b);
	if (!flag)
		flag = (stu_b->de + stu_b->cai) - (stu_a->cai + stu_a->de);
	if (!flag)
		flag = stu_b->de - stu_a->de;
	if (!flag)
		flag = stu_a->number - stu_b->number;

	return flag;
}
int main(void)
{
	int n = 0;
	int number = 0, de = 0, cai = 0;
	int count = 0;
	student stu[N] = {0};

	scanf("%d %d %d", &n, &L, &H);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &number, &de, &cai); 
		if (de >= L && cai >= L)
		{
			count++;
			stu[count - 1].number = number;
			stu[count - 1].de = de;
			stu[count - 1].cai = cai;
		}
	}

	qsort(stu, count, sizeof(student), compare_student);

	printf("%d\n", count);
	for (int i = 0; i < count; ++i)
		printf("%d %d %d\n", stu[i].number, stu[i].de, stu[i].cai);

	return 0;
}
