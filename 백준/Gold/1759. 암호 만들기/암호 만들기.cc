#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int L, C;
vector<char> v;
int path[20];

void backtracking(int n, string s)
{
    if (n == L)
    {
        int consonant = 0;
        int vowel = 0;

        for (int i = 0; i < L; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                vowel += 1;
            }
            else
            {
                consonant += 1;
            }
        }

        if (vowel >= 1 && consonant >= 2)
        {
            cout << s << "\n";
        }
        return;
    }
    else
    {
        for (int i = 0; i < C; i++)
        {
            if (n == 0 || path[n - 1] < i)
            {
                path[n] = i;
                backtracking(n + 1, s + v[i]);
            }
        }
    }
}

int main()
{
    FASTIO();
    cin >> L >> C;

    for (int i = 0; i < C; i++)
    {
        char c;
        cin >> c;

        v.push_back(c);
    }

    sort(v.begin(), v.end());

    backtracking(0, "");

    return 0;
}