#include<iostream>
#include<string>

using namespace std;

bool isCorrect(string &s)
{
    int a{0}, b{0}, c{0};
    bool p{false}, t{false};
    for (auto ch : s) {
        switch (ch) {
        case 'P':
            if (p)
                return false;
            else
                p = true;
            break;
        case 'A':
            if (!p)
                ++a;
            else if (p && !t)
                ++b;
            else if (t)
                ++c;
            break;
        case 'T':
            if (t)
                return false;
            else
                t = true;
            break;
        default:
            return false;
        }
    }

    if (p && t && b && a * b == c)
        return true;

    return false;
}

int main(void)
{
    int n;
    cin >> n;
    string input[n];
    for (auto &s : input)
        cin >> s;
    for (auto &s : input) {
        if (isCorrect(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
