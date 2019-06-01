#include<iostream>

int main(void)
{
    int n, m;
    std::cin >> n >> m;
    int a[n];
    for (int i = 0; i != n; ++i)
        std::cin >> a[i];

    for (int i = n - m % n; i != n; ++i) {
        if (i != n - m % n)
            std::cout << ' ';
        std::cout << a[i];
    }
    for (int i = 0; i != n - m % n; ++i) {
        if (i || m % n)
            std::cout << ' ';
        std::cout << a[i];
    }

    return 0;
}
