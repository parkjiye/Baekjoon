#include <iostream>
#include <map>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO();
    string s;
    cin >> s;
    map<char, int> m;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c == '6' || c == '9')
        {
            if (m.find('6') != m.end())
            {
                m['6'] += 1;
            }
            else
            {
                m.insert({'6', 1});
            }
        }
        else
        {
            if (m.find(c) != m.end())
            {
                m[c] += 1;
            }
            else
            {
                m.insert({c, 1});
            }
        }
    }

    int ans = 0;

    for (auto it = m.begin(); it != m.end(); it++)
    {
        int num = it->second;

        if (it->first == '6')
        {
            num /= 2;

            if (it->second % 2 == 1)
            {
                num += 1;
            }
        }

        if (num > ans)
        {
            ans = num;
        }
    }

    cout << ans << "\n";
}