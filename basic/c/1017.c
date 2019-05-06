#include<stdio.h>

int main(void)
{
        char A[1004] = {0}, Q[1004] = {0};
        int B = 0, r = 0;

        scanf("%s %d", A, &B);
        for (int i = 0; A[i] != '\0'; ++i) {
                Q[i] = (r * 10 + A[i] - '0') / B + '0';
                r = (r * 10 + A[i] - '0') % B;
        }
        printf("%s %d\n", Q[0] == '0' && Q[1] != '\0' ? &Q[1] : Q, r);

        return 0;
}
