#include<stdio.h>

int main(void)
{
        int n = 0;
        long long a, b, c;
        int ans[10] = {0};

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
                scanf("%lld %lld %lld", &a, &b, &c);
                if (a + b > c)
                        ans[i] = 1;
        }
        for (int i = 0; i < n; ++i) {
                if (ans[i])
                        printf("Case #%d: true\n", i + 1);
                else
                        printf("Case #%d: false\n", i + 1);
        }

        return 0;
}
