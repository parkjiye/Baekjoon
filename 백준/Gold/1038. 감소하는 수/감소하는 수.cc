#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int cnt;
int path[10];
int number[10];

vector<string> v;

bool compare(string a, string b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }
    return a.length() < b.length();
}

void backtracking(int digit, int idx)
{
    if (digit == idx)
    {
        cnt += 1;

        string s;
        for (int i = 0; i < digit; i++)
        {
            // cout << number[path[i]] << " ";
            s += to_string(number[path[i]]);
        }
        v.push_back(s);
        // cout << s << " " << cnt << "\n";
        return;
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            if (idx == 0 || path[idx - 1] < i)
            {
                path[idx] = i;
                // cout << path[idx] << "\n";
                backtracking(digit, idx + 1);
            }
        }
    }
}

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i <= 9; i++)
    {
        number[i] = 9 - i;
    }

    if (N > 1022)
    {
        cout << -1 << "\n";
        return 0;
    }

    if (N <= 9)
    {
        cout << N << "\n";
        return 0;
    }

    cnt = 9;

    for (int i = 0; i <= 9; i++)
    {
        v.push_back(to_string(i));
    }

    for (int i = 2; i <= 10; i++)
    {
        if (N > cnt)
        {
            backtracking(i, 0);
        }

        if (N <= cnt)
        {
            sort(v.begin(), v.end(), compare);
            cout << v[N] << "\n";
            return 0;
        }
    }
}