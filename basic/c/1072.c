#include<stdio.h>

#define N 1000
#define M 6
#define K 10

typedef struct student{
        char name[8];
        int num;
        int code[10];
}student;

int main(void)
{
        int m = 0, n = 0;
        int code[M] = {0};
        int total_stu_num = 0;
        int total_code_num = 0;
        int stu_code_num = 0;
        int stu_contraband_code[M] = {0};
        student stu[N] = {0};

        scanf("%d %d", &n, &m);

        for (int i = 0; i < m; ++i)
                scanf("%d", &code[i]);
        for (int i = 0; i < n; ++i){
                scanf("%s%d", stu[i].name, &stu[i].num);
                for (int j = 0; j < stu[i].num; ++j)
                        scanf("%d", &stu[i].code[j]);
        }

        for (int i = 0; i < n; ++i){
                stu_code_num = 0;
                memset(stu_contraband_code, 0, sizeof(stu_contraband_code));
                for (int k = 0; k < stu[i].num; ++k)
                        for (int j = 0; j < m; ++j)
                                if (code[j] == stu[i].code[k]){
                                        ++stu_code_num;
                                        stu_contraband_code[stu_code_num - 1] = code[j];
                                        break;
                                }
                if (stu_code_num){
                        printf("%s:", stu[i].name);
                        for (int i = 0; i < stu_code_num; ++i)
                                printf(" %04d", stu_contraband_code[i]);
                        printf("\n");
                        ++total_stu_num;
                        total_code_num += stu_code_num;
                }
        }
        printf("%d %d\n", total_stu_num, total_code_num);

        return 0;
}
