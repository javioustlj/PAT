#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iterator>

using namespace std;

int main(void)
{
    string s;
    getline(cin, s);
    istringstream iss(s);
    vector<string> ans(istream_iterator<string>{iss}, istream_iterator<string>());
    for (auto it = ans.crbegin(); it != ans.crend(); ++it) {
        cout << *it;
        if (it != ans.crend())
            cout << ' ';
    }
    cout << endl;

    return 0;
}
