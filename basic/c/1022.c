#include<stdio.h>

int main(void)
{
        unsigned a = 0, b = 0, d = 0;
        unsigned seq[32] = {0};
        int count = 0;

        scanf("%u %u %u", &a, &b, &d);
        a += b;
        do {
                seq[count++] = a % d;
                a /= d;
        } while(a);
        for (int i = count - 1; i >= 0; --i)
                printf("%u", seq[i]);
        putchar('\n');
        
        return 0;
}
