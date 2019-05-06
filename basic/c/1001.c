#include<stdio.h>

int main(void)
{
        unsigned n, cnt = 0;

        scanf("%u", &n);

        while(n != 1) {
                n % 2 ? n = (3 * n + 1) / 2 : n /= 2;
                ++cnt;
        }

        printf("%u\n", cnt);

        return 0;
}
