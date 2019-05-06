#include<stdio.h>

int main(void)
{
        int cnt[10] = {0};

        for (int i = 0; i < 10; ++i)
                scanf("%d", &cnt[i]);
        for (int i = 1; i < 10; ++i) {
                if (cnt[i] > 0) {
                        printf("%d", i);
                        cnt[i]--;
                        break;
                }
        }
        for (int i = 0; i < 10; ++i)
                for (int j = 0; j < cnt[i]; ++j)
                        printf("%d", i);
        putchar('\n');

        return 0;
}
