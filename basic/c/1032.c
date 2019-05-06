#include<stdio.h>

#define N 100001

int school[N] = {0};

int main(void)
{
        int n = 0, num = 0, max = 0;
        int score = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
                scanf("%d %d", &num, &score);
                school[num] += score;
        }
        //学校是从1开始编号的，所以这里是n+1，对应测试点2
        for (int i = 0; i < n + 1; ++i) {
                if (school[i] >= school[max])
                        max = i;
        }
        printf("%d %d\n", max, school[max]);

        return 0;
}
