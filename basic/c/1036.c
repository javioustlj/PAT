#include<stdio.h>

int main(void)
{
        int n = 0;
        char c = 0;
        scanf("%d %c", &n, &c);

        for (int i = 0; i < n; ++i)
                putchar(c);
        putchar('\n');
        for (int i = 0; i < (n + 1) / 2 - 2; ++i){
                putchar(c);
                for (int j = 0; j < n - 2; ++j)
                        putchar(' ');
                putchar(c);
                putchar('\n');
        }
        for (int i = 0; i < n; ++i)
                putchar(c);
        putchar('\n');

        return 0;
}
