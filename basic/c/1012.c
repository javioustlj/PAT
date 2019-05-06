#include<stdio.h>

#define N 1000
#define PRINT(a, cnt)  cnt ? printf("%d", a) : printf("N")

int main(void)
{
        int n = 0, r = 0, flag = 1;
        int a[5] = {0};
        int cnt[5] = {0};
        int data[N] = {0};

        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
                scanf("%d", &data[i]);

        for (int i = 0; i < n; ++i) {
                r = data[i] % 5;
                switch (r) {
                        case 0: 
                                if (data[i] % 2 == 0) {
                                        a[0] += data[i];
                                        ++cnt[0];
                                }
                                break;
                        case 1:
                                a[1] += data[i] * flag;
                                flag *= -1;
                                ++cnt[1];
                                break;
                        case 2:
                                ++cnt[2];
                                break;
                        case 3:
                                a[3] += data[i];
                                ++cnt[3];
                                break;
                        case 4:
                                if (a[4] < data[i])
                                        a[4] = data[i];
                                ++cnt[4];
                                break;
                        default:
                                break;
                }
        }

        a[2] = cnt[2];
        for (int i = 0; i < 5; ++i) {
                if (i == 3) {
                        if (cnt[3]) {
                                printf("%.1f", (double)a[3] / cnt[i]);
                        } else {
                                printf("N");
                        }
                } else {
                        PRINT(a[i], cnt[i]);
                }
                printf("%c", i < 4 ? ' ' : '\0');
        }
        printf("\n");

        return 0;
}
