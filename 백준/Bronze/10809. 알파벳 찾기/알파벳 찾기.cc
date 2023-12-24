#include <iostream>
#include <map>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

string s;
map<char, int> m;

int main()
{
    FASTIO();
    cin >> s;

    for (int i = 0; i < 26; i++)
    {
        m.insert({(char(i + 97)), -1});
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (m[s[i]] == -1)
        {
            m[s[i]] = i;
        }
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->second << " ";
    }
    cout << "\n";
}