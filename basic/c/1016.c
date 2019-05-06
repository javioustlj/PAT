#include<stdio.h>

int main(void)
{
        char A[20] = {0};
        char B[20] = {0};
        int a = 0, b = 0;
        int pa = 0, pb = 0;

        scanf("%s %d %s %d", A, &a, B, &b);

        for (int i = 0; A[i] != '\0'; ++i) {
                if (A[i] - '0' == a)
                        pa = pa * 10 + a;
        }
        for (int i = 0; B[i] != '\0'; ++i) {
                if (B[i] - '0' == b)
                        pb = pb * 10 + b;
        }

        printf("%d\n", pa + pb);

        return 0;
}
