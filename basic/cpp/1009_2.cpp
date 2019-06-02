#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void)
{
    string s;
    vector<string> ans;
    while (cin >> s)
        ans.push_back(s);
    for (auto it = ans.crbegin(); it != ans.crend(); ++it) {
        cout << *it;
        if (it != ans.crend() - 1)
            cout << ' ';
    }
    cout << endl;

    return 0;
}
