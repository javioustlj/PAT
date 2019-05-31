#include<iostream>

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; ++i)
        if ( n % i == 0)
            return false;
    return true;
}

int main(void)
{
    int n, cnt{0};
    std::cin >> n;
    for (int i = 5; i <= n; i += 2)
        if (isPrime(i) && isPrime(i - 2))
            ++cnt;
    std::cout << cnt << std::endl;

    return 0;
}
