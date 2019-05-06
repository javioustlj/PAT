#include<stdio.h>

void recordWin(char c, int cnt[])
{
        switch (c) {
                case 'B': ++cnt[0];
                          break;
                case 'C': ++cnt[1];
                          break;
                case 'J': ++cnt[2];
                          break;
                default:
                          break;
        }
}

char getMaxWin(int cnt[])
{
        int index = 0;
        char name[3] = {'B', 'C', 'J'};

        for (int i = 0; i < 3; ++i) {
                if (cnt[index] < cnt[i])
                       index = i; 
        }

        return name[index];
}

int main(void)
{
        char a, b;
        int n;
        int cnt_ping = 0, cnt_win = 0, cnt_lose = 0;
        int cntAWin[3] = {0}, cntBWin[3] = {0};

        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; ++i) {
                scanf("%c", &a);
                getchar();
                scanf("%c", &b);
                getchar();
                if (a == b) {
                        ++cnt_ping;
                } else if ((a == 'C' && b == 'J') || 
                           (a == 'J' && b == 'B') ||
                           (a == 'B' && b == 'C')) {
                        ++cnt_win;
                        recordWin(a, cntAWin);
                } else {
                        ++cnt_lose;
                        recordWin(b, cntBWin);
                }
        }

        printf("%d %d %d\n", cnt_win, cnt_ping, cnt_lose);
        printf("%d %d %d\n", cnt_lose, cnt_ping, cnt_win);
        printf("%c %c\n", getMaxWin(cntAWin), getMaxWin(cntBWin));

        return 0;
}
