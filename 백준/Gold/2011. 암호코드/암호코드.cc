#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

string s;
long long int dp[5005];

int main()
{
    FASTIO();
    cin >> s;

    if (s[0] != '0')
    {
        dp[0] = 1;
    }
    else
    {
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            cout << 0 << "\n";
            return 0;
        }

        if (s[i] == '0')
        {
            if (i == 0)
            {
                cout << 0 << "\n";
                return 0;
            }
            else if (i == s.length() - 1)
            {
                string f = s.substr(i - 1, 1);
                if (stoi(f) >= 3 || stoi(f) == 0)
                {
                    cout << 0 << "\n";
                    return 0;
                }
                else
                {
                    if (i == 1)
                    {
                        dp[i] = 1;
                    }
                    else
                    {
                        dp[i] = dp[i - 2];
                    }
                    continue;
                }
            }
            else
            {
                string f = s.substr(i - 1, 1);
                if (stoi(f) >= 3 || stoi(f) == 0)
                {
                    cout << 0 << "\n";
                    return 0;
                }
                else
                {
                    if (i == 1)
                    {
                        dp[i] = 1;
                    }
                    else
                    {
                        dp[i] = dp[i - 2];
                    }
                    continue;
                }
            }
        }

        string w = s.substr(i - 1, 2);

        if (stoi(w) <= 26 && s[i - 1] != '0' && s[i] != '0')
        {
            if (i == 1)
            {
                dp[i] = dp[i - 1] + 1;
            }
            else
            {
                dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000;
            }
        }
        else
        {
            dp[i] = dp[i - 1] % 1000000;
        }
    }

    cout << dp[s.length() - 1] << "\n";
}