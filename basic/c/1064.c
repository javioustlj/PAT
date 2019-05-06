#include<stdio.h>

int main(void)
{
        int card[37] = {0};
        int n = 0, m = 0;
        int sum = 0, count = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; ++i){
                scanf("%d", &m);
                for (sum = 0; m; m /= 10)
                        sum += m % 10;
                if (!card[sum])
                        ++card[sum], ++count;
        }

        printf("%d\n", count);
        for (int i = 0; i < 37; ++i)
                if (card[i])
                        printf("%d%c", i, --count ? ' ' : '\0');
        
        return 0;
}
