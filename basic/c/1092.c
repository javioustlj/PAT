#include<stdio.h>

#define M 100
#define N 1000

int main(void)
{
        int n = 0, m = 0, cake[N] = {0}, sals = 0, flag = 0, max = 0;

        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                        scanf("%d", &sals);
                        cake[j] += sals;
                }
        }
        for (int i = 0; i < n; ++i)
                if (max < cake[i])
                        max = cake[i];
        printf("%d\n", max);
        for (int i = 0; i < n; ++i) {
                if (cake[i] == max) {
                        if (flag) {
                                putchar(' ');
                        } else {
                                flag = 1;
                        }
                        printf("%d", i + 1);
                }
        }

        return 0;
}
