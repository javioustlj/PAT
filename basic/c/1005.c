#include<stdio.h>
#include<stdlib.h>

#define N 100

int compare_number(const void *a, const void *b)
{
        return *(int *)b - *(int *)a;
}
int main(void)
{
        int n = 0, j = 0;
        int seq[N] = {0};
        int temp = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        	scanf("%d", &seq[i]);

        for (int i = 0; i < n; ++i) {
                if (seq[i]) {
                        temp = seq[i];
                        while (temp != 1) {
                                temp = temp % 2 ? (temp * 3 + 1) / 2 : temp / 2;
                                for (int i = 0; i < n; ++i)
                                        if (temp == seq[i])
                                                seq[i] = 0;
                        }
                }
        }
        qsort(seq, n, sizeof(int), compare_number);

        if (seq[0])
                printf("%d", seq[0]);
        while (seq[++j] != 0)
                printf(" %d", seq[j]);

        return 0;
}
