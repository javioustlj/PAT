#include<iostream>
#include<map>

int main(void)
{
    int coefficient, index;
    std::map<int, int> poly;
    std::map<int, int> derivative;
    while (std::cin >> coefficient >> index)
        poly[index] = coefficient;

    if (poly.size() == 1 && poly.count(0)) {
        std::cout << "0 0" << std::endl;
        return 0;
    }
    for (const auto &c : poly) {
        int t = c.first * c.second;
        if (t)
            derivative.insert({c.first - 1, t});
    }
    for (auto it = derivative.crbegin(); it != derivative.crend(); ++it) {
        if (it != derivative.crbegin())
            std::cout << ' ';
        std::cout << (*it).second << ' ' << (*it).first;
    }
    std::cout << std::endl;

    return 0;
}
