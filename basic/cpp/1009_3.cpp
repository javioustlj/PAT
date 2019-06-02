#include<iostream>
#include<stack>
#include<string>

int main(void)
{
    std::string s;
    std::stack<std::string> ans;
    while (std::cin >> s)
        ans.push(s);

    while (!ans.empty()) {
        std::cout << ans.top();
        ans.pop();
        if (!ans.empty())
            std::cout << ' ';
    }
    std::cout << std::endl;

    return 0;
}
