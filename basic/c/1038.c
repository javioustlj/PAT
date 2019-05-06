#include<stdio.h>

int main(void)
{
        int count[101] = {0};
        int n = 0, m = 0;
        int score = 0;
        int a[100000] = {0};

        scanf("%d", &n);
        for (int i = 0; i < n; ++i){
                scanf("%d", &score);
                ++count[score];
        }
        scanf("%d", &m);
        for (int i = 0; i < m; ++i)
                scanf("%d", &a[i]);
        for (int i = 0; i < m; ++i)
                printf("%d%c", count[a[i]], i == m - 1 ? '\0' : ' ');

        return 0;
}
