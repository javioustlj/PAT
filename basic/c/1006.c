#include<stdio.h>

int main(void)
{
        int n = 0; 

        scanf("%d", &n);
        for (int i = 0; i < n / 100; ++i)
                putchar('B');
        for (int i = 0; i < n % 100 / 10; ++i)
                putchar('S');
        for (int i = 1; i <= n % 10; ++i)
                printf("%d", i);
        putchar('\n');

        return 0;
}
