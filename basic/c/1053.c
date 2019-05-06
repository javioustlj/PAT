#include<stdio.h>

int main(void)
{
        int n = 0, D = 0, k = 0;
        int count_vacancy = 0; //住房空置数
        int count_possible_vacancy = 0; //可能住房空置数
        int count_day = 0;
        double e = 0;
        double energe_used = 0;

        scanf("%d %lf %d", &n, &e, &D);
        for (int i = 0; i < n; ++i){
                scanf("%d", &k);
                count_day = 0;
                for (int j = 0; j < k; ++j){
                        scanf("%lf", &energe_used);
                        if (energe_used < e)
                                ++count_day;
                }
                if (count_day > k / 2){
                        if (k > D)
                                ++count_vacancy;
                        else
                                ++count_possible_vacancy;
                }
        }

        printf("%.1f%% %.1f%%\n", 100.0 * count_possible_vacancy / n, 100.0 * count_vacancy / n);

        return 0;
}
