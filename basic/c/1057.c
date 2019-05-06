#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
        int N = 0;
        int len = 0;
        char str[100004];
        int count_0 = 0, count_1 = 0;

        gets(str);
        len = strlen(str);
        for (int i = 0; i < len; ++i){
                if (isupper(str[i]))
                        N += str[i] - 'A' + 1;
                else if (islower(str[i]))
                        N += str[i] - 'a' + 1;
        }

        while (N){
                if (N & 1)
                        ++count_1;
                else
                        ++count_0;
                N = N >> 1;
        }

        printf("%d %d", count_0, count_1);

        return 0;
}
