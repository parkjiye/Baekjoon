#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s, ans = "";
    cin >> s;

    vector<char> v;
    for (int i = 0; i < s.length(); i++)
    {
        v.push_back(s[i]);
    }

    sort(v.begin(), v.end(), greater<char>());

    for (int i = 0; i < s.length(); i++)
    {
        ans += v[i];
    }

    cout << ans << "\n";
}