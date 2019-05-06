#include<stdio.h>
#include<stdlib.h>

int compare_number(const void *a, const void *b)
{
        return ( *(int *)a - *(int *)b);
}

int main(void)
{
        int n = 0, n1 = 0, n2 = 0;
        int seq[4] = {0};

        scanf("%d", &n);
        while (1) {
                for (int i = 0; i < 4; ++i) {
                        seq[i] = n % 10;
                        n /= 10;
                }

                qsort(seq, 4, sizeof(int), compare_number);
                n1 = ((seq[3] * 10 + seq[2]) * 10 + seq[1]) * 10 + seq[0];
                n2 = ((seq[0] * 10 + seq[1]) * 10 + seq[2]) * 10 + seq[3];
                n = n1 - n2;
                printf("%04d - %04d = %04d\n", n1, n2, n);
                if (n == 6174 || n == 0)
                        break;
        }

        return 0;
}
