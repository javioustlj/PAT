#include<stdio.h>

int main(void)
{
        int T = 0, K = 0;
        int n1, b, t, n2;

        scanf("%d %d", &T, &K);

        for (int i = 0; i < K; ++i){
                scanf("%d %d %d %d", &n1, &b, &t, &n2);
                if (t > T){
                        printf("Not enough tokens.  Total = %d.\n", T);
                        continue;
                }
                if (n2 > n1){
                        if (b){
                                printf("Win %d!  ", t);
                                T += t;
                        }
                        else {
                                printf("Lose %d.  ", t);
                                T -= t;
                        }
                }
                else {
                        if (!b){
                                printf("Win %d!  ", t);
                                T += t;
                        }
                        else {
                                printf("Lose %d.  ", t);
                                T -= t;
                        }
                }
                printf("Total = %d.\n", T);
                if (!T){
                        printf("Game Over.\n");
                        break;
                }
        }

        return 0;
}
