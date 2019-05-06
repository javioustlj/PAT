#include<stdio.h>

#define CLK_TCK 100

int main(void)
{
        int c1 = 0, c2 = 0, t = 0;
        int h, m, s;

        scanf("%d %d", &c1, &c2);
        
        t = (c2 - c1 + 50) / CLK_TCK;
        h = t / 3600;
        m = t % 3600 / 60;
        s = t % 60;

        printf("%02d:%02d:%02d\n", h, m, s);

        return 0;
}
