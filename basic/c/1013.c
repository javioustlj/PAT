#include<stdio.h>
#include<stdbool.h>

#define N 10001

bool is_prime(int n)
{
        for (int i = 2; i <= sqrt(n); ++i)
                if (n % i == 0) 
                        return false;

        return true;
}

void getAllPrimes(int prime[N])
{
        for (int i = 2, j = 1; j < N; ++i) {
                if (is_prime(i)) {
                        prime[j++] = i;
                }
        }
}

int main(void)
{
        int m = 0, n = 0;
        int prime[N] = {0};

        scanf("%d %d", &m, &n);

        getAllPrimes(prime);

        for (int i = m; i <= n; ++i) {
                printf("%d%c", prime[i], (i - m + 1) % 10 && i != n ? ' ' : '\n');
        }

        return 0;
}
