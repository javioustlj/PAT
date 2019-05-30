#include<iostream>

int main(void)
{
    int n;
    std::cin >> n;

    for (int i = 0; i != n / 100; ++i)
        std::cout << 'B';
    for (int i = 0; i != n / 10 % 10; ++i)
        std::cout << 'S';
    for (int i = 0; i != n % 10; ++i)
        std::cout << i + 1;
    std::cout << std::endl;

    return 0;
}
