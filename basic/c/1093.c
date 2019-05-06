#include<stdio.h>
#include<string.h>

#define N 1000004
int cnt;

void getOutput(char *s, char output[])
{
        for (int i = 0; s[i] != '\0'; ++i) {
                if (NULL == strchr(output, s[i]) && s[i] != '\n')
                                output[cnt++] = s[i];
        }
}

int main(void)
{
        char A[N] = {0}, B[N] = {0}, output[128] = {0};

        fgets(A, N, stdin);
        fgets(B, N, stdin);

        getOutput(A, output);
        getOutput(B, output);

        puts(output);

        return 0;
}
