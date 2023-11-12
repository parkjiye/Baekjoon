#include <iostream>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int str[2005];
int dp[2005][2005];

int main()
{
    FASTIO();
    cin >> N;

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        str[i] = x;
        dp[i][i] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        dp[i][i + 1] = (str[i] == str[i + 1] ? 1 : 0);
    }

    for (int i = 2; i < N; i++)
    {
        for (int j = 0; j < N - i; j++)
        {
            if (str[j] == str[j + i] && dp[j + 1][j + i - 1] == 1)
            {
                dp[j][j + i] = 1;
            }
            else
            {
                dp[j][j + i] = 0;
            }
        }
    }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;

        cout << dp[s - 1][e - 1] << "\n";
    }
}