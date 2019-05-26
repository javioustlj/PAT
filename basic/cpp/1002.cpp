#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    int sum{0};
    for (auto c : s)
        sum += c - '0';
    vector<int> index;
    while (sum) {
        index.push_back(sum % 10);
        sum /= 10;
    }

    string numstr[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    for (auto it = index.rbegin(); it != index.rend(); ++it) {
        cout << numstr[*it];
        if (it + 1 != index.rend())
            cout << ' ';
    }
    cout << endl;

    return 0;
}
