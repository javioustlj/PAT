#include<iostream>

int main(void)
{
    int t;
    std::cin >> t;
    long long a[t][3];
    for (int i = 0; i != t; ++i)
        std::cin >> a[i][0] >> a[i][1] >> a[i][2];
    for (int i = 0; i != t; ++i) {
        if (a[i][0] + a[i][1] > a[i][2])
            std::cout << "Case #" << i + 1 << ": true" << std::endl;
        else
            std::cout << "Case #" << i + 1 << ": false" << std::endl;
    }

    return 0;
}
