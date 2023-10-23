#include <iostream>
#include <algorithm>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO();

    string s;
    cin >> s;

    int zero = 0;
    int one = 0;

    int temp = s[0];

    if (s[0] == '0')
    {
        zero += 1;
    }
    else
    {
        one += 1;
    }

    for (int i = 1; i < s.length(); i++)
    {
        if (temp != s[i])
        {
            if (s[i] == '0')
            {
                zero += 1;
            }
            else
            {
                one += 1;
            }

            temp = s[i];
        }
    }

    cout << min(zero, one) << "\n";
}