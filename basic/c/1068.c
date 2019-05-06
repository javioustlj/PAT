#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define M 1000
#define N 1000

int image[N][M] = {0};
int m = 0, n = 0, TOL = 0;

bool is_red(int x, int y)
{
        int color = image[x][y];
        for (int i = -1; i != 2; ++i)
                for (int j = -1; j != 2; ++j){
                        int xx = x + i;
                        int yy = y + j;
                        if (xx >= 0 && xx < n && yy >= 0 && yy < m && (i != 0 || j != 0)
                                        && abs(color - image[xx][yy]) <= TOL)
                                return false;
                }

        return true;                
}
bool is_unique(int x, int y)
{
        int color = image[x][y];
        for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                        if (color == image[i][j] && (x != i || y != j))
                                return false;
        return true;
}
int main(void)
{
        int x = 0, y = 0;
        int cnt = 0;

        scanf("%d %d %d", &m, &n, &TOL);
        for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                        scanf("%d", &image[i][j]);

        for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                        if (is_red(i, j) && is_unique(i, j)){
                                if (!cnt){
                                        x = i + 1;
                                        y = j + 1;
                                        ++cnt;
                                }
                                else {
                                        ++cnt;
                                        goto print;
                                }
                        }
print: 
        switch (cnt){
                case 0:
                        printf("Not Exist\n");
                        break;
                case 1:
                        printf("(%d, %d): %d\n", y, x, image[x - 1][y - 1]);
                        break;
                case 2:
                        printf("Not Unique\n");
                        break;
                default:
                        break;
        }

        return 0;
}
