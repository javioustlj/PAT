#include<stdio.h>

int main(void)
{
        char N[1004] = {0};
        int cnt[10] = {0};
        
        scanf("%s", N);

        for (int i = 0; N[i] != '\0'; ++i)
                ++cnt[N[i] - '0'];
        for (int i = 0; i < 10; ++i) {
                if (cnt[i])
                        printf("%d:%d\n", i, cnt[i]);
        }

        return 0;
}
