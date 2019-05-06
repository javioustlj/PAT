#include<stdio.h>
#include<stdlib.h>

int main(void)
{
        long long int p = 0, a = 0, change = 0;
        int pg = 0, ps = 0, pk = 0;
        int ag = 0, as = 0, ak = 0;

        scanf("%d.%d.%d", &pg, &ps, &pk);
        scanf("%d.%d.%d", &ag, &as, &ak);

        p = (long long int)(pg * 17 + ps) * 29 + pk;
        a = (long long int)(ag * 17 + as) * 29 + ak;

        change = a - p;
        if (change < 0){
                putchar('-');
                change = -change;
        }
        printf("%ld.%ld.%ld\n", change / (17 * 29), change / 29 % 17, change % 29);

        return 0;
}
