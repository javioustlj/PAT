#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    int sum{0};
    for (auto c : s)
        sum += c - '0';
    string num = to_string(sum);

    string numstr[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    for (auto c : num) {
        if (c != num[0])
            cout << ' ';
        cout << numstr[c - '0'];
    }
    cout << endl;

    return 0;
}
