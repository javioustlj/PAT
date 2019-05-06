#include<stdio.h>
#include<stdbool.h>

#define M 20
#define N 10

bool isAutomorphic(int n, int K)
{
        int product = n * K * K;
        while (K != 0) {
                if (K % 10 != product % 10)
                        return false;
                K /= 10;
                product /= 10;
        }
        return true;
}

int main(void)
{
        int m = 0, a[M] = {0}, flag = 0;

        scanf("%d", &m);
        for (int i = 0; i < m; ++i)
                scanf("%d", &a[i]);
        for (int i = 0; i < m; ++i) {
                flag = 0;
                for (int j = 1; j < N; ++j) {
                        if (isAutomorphic(j, a[i])) {
                                printf("%d %d\n", j, j * a[i] * a[i]);
                                flag = 1;
                                break;
                        }
                }
                if (!flag)
                        printf("No\n");
        }

        return 0;
}
