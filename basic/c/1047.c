#include<stdio.h>

#define N 1000
int main(void)
{
        int team[N + 1] = {0};
        int max = 0;
        int n = 0;
        int team_num, self_num, score;
        int index;

        scanf("%d", &n);
        for (int i = 0; i < n; ++i){
                scanf("%d-%d %d", &team_num, &self_num, &score);
                team[team_num] += score;
        }
        for (int i = 1; i < N + 1; ++i)
                if (max < team[i]){
                        max = team[i];
                        index = i;
                }

        printf("%d %d\n", index, max);

        return 0;
}
