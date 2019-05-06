#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool isPrime(int n)
{
        for (int i = 2; i <= sqrt(n); ++i) {
                if (n % i == 0)
                        return false;
        }
        return true;
}

int main(void)
{
        int n = 0, cnt = 0;

        scanf("%d", &n);
        for (int i = 3; i + 2 <= n; i += 2) {
                if (isPrime(i) && isPrime(i + 2))
                        ++cnt;
        }

        printf("%d", cnt);

        return 0;
}
