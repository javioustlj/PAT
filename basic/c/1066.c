#include<stdio.h>

#define M 500
#define N 500

int main(void)
{
        int m = 0, n = 0, a = 0, b = 0, replacement = 0;
        int image[M][N] = {0};

        scanf("%d %d %d %d %d", &m, &n, &a, &b, &replacement);
        for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                        scanf("%d", &image[i][j]);
        for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                        if (a <= image[i][j] && image[i][j] <= b)
                                image[i][j] = replacement;
        for (int i = 0; i < m; ++i){
                printf("%03d", image[i][0]);
                for (int j = 1; j < n; ++j)
                        printf(" %03d", image[i][j]);
                printf("\n");
        }

        return 0;
}
