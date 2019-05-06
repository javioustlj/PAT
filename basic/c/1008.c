#include<stdio.h>

#define N 100

int main(void)
{
        int n = 0, m = 0;
        int a[N] = {0};

        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i)
                scanf("%d", &a[i]);

        m %= n;
        for (int i = n - m; i < n; ++i)
                printf("%d%c", a[i], m == n && i == n - 1 ? '\0' : ' ');
        for (int i = 0; i < n - m; ++i)
                printf("%d%c", a[i], i == n - m - 1 ? '\0' : ' ');

        return 0;
}
