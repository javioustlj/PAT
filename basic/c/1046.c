#include<stdio.h>

int main(void)
{
        int a1, a2, b1, b2;
        int n;
        int cnta = 0, cntb = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; ++i){
                scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
                if (a2 == a1 + b1 && b2 != a1 + b1)
                        ++cntb;
                else if(b2 == a1 + b1 && a2 != a1 + b1)
                        ++cnta;
        }

        printf("%d %d\n", cnta, cntb);

        return 0;
}
