#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(void)
{
    int k, n;
    vector<int> v;
    cin >> k;
    for (int i = 0; i != k; ++i) {
        cin >> n;
        v.push_back(n);
    }

    set<int> ans(v.cbegin(), v.cend());
    for (auto c : v) {
        while (c != 1) {
            c = c % 2 ? (c * 3 + 1) / 2 : c / 2;
            ans.erase(c);
        }
    }

    for (auto it = ans.crbegin(); it != ans.crend(); ++it) {
        if (it != ans.crbegin())
            cout << ' ';
        cout << *it;
    }
    cout << endl;

    return 0;
}
