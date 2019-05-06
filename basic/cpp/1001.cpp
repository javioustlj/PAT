#include<iostream>

int main()
{
    unsigned n, cnt{0};

    std::cin >> n;

    while (n != 1) {
        n % 2 ? n = (3 * n + 1) / 2 : n /= 2;
        ++cnt;
    }

    std::cout << cnt << std::endl;

    return 0;
}
