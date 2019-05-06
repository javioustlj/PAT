#include<stdio.h>

#define N 10

int main(void)
{
        int n = 0, sum = 0;
        int seq[N] = {0};

        scanf("%d", &n);

        for (int i = 0; i < n; ++i)
                scanf("%d", &seq[i]);
        for (int i = 0; i < n; ++i)
                sum += seq[i];
        sum *= 11 * (n - 1);

        printf("%d\n", sum);

        return 0;
}
