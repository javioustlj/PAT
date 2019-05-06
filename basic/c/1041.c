#include<stdio.h>

#define N 1000
#define M 1000

typedef struct student{
        int a;
        int b;
        char ID[16];
}student;

int main(void)
{
        int n = 0, m = 0;
        student stu[N] = {0};
        int al[M] = {0};

        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
                scanf("%s %d %d", stu[i].ID, &stu[i].a, &stu[i].b);
        
        scanf("%d", &m);
        for (int i = 0; i < m; ++i)
                scanf("%d", &al[i]); 

        for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                        if (al[i] == stu[j].a)
                                printf("%s %d\n", stu[j].ID, stu[j].b);

        return 0;
}
