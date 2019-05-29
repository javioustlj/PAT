#include<stdio.h>

#define K 100

int main(void)
{
        int k, n, a[K], ans[K + 1] = {0};

        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
                scanf("%d", &a[i]);
                ans[a[i]] = 1;
        }

        for (int i = 0; i < k; ++i) {
                n = a[i];
                while ( n != 1) {
                        n = n % 2 ? ( n * 3 + 1) / 2 : n / 2;
                        if (n <= 100)
                                ans[n] = 0;
                }
        }

        int first = 1;
        for (int i = 0; i <= 100; ++i) {
                if (ans[100 - i]) {
                        if (!first)
                                putchar(' ');
                        printf("%d", 100 - i);
                        first = 0;
                }
        }

        return 0;
}
