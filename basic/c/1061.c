#include<stdio.h>

#define M 100
#define N 100

int main(void)
{
        int n, m;
        int stu_ans = 0;
        int ans[M] = {0};
        int score[M] = {0};
        int stu_score[N] = {0};

        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i)
                scanf("%d", &score[i]);
        for (int i = 0; i < m; ++i)
                scanf("%d", &ans[i]);
        for (int i = 0; i < n; ++i){
                for (int j = 0; j < m; ++j){
                        scanf("%d", &stu_ans);
                        if (stu_ans == ans[j])
                                stu_score[i] += score[j];
                }
        }

        for (int i = 0; i < n; ++i)
                printf("%d\n", stu_score[i]);

        return 0;
}
