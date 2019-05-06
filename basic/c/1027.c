#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void)
{
        int N = 0, n = 0;
        char c = 0;

        scanf("%d %c", &N, &c);
        n = sqrt((N + 1) / 2);
        for (int i = 0; i < 2 * n - 1; ++i) {
                for (int j = 0; j < n - 1 - abs(n - 1 - i); ++j)
                        putchar(' ');
                for (int j = 0; j < 2 * abs(n - 1 - i) + 1; ++j)
                        putchar(c);
                putchar('\n');
        }
        printf("%d\n", N + 1 - 2 * n * n);

        return 0;
}
