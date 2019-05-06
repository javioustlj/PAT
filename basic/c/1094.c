#include<stdio.h>
#include<stdbool.h>
#include<math.h>

#define L 1004

bool isPrime(int n)
{
        for (int i = 2; i <= sqrt(n); ++i)
                if (n % i == 0)
                        return false;

        return true;
}

int main(void)
{
        int l = 0, k = 0, sum = 0;
        char s[L] = {0};

        scanf("%d %d", &l, &k);
        scanf("%s", s);

        for (int i = 0; s[i + k - 1] != '\0'; ++i) {
                sum = 0;
                for (int j = 0; j < k; ++j)
                        sum = sum * 10 + s[i + j] - '0';
                if (isPrime(sum)) {
                        printf("%0*d\n", k, sum);
                        return 0;
                }
        }
        puts("404");
        
        return 0;
}
