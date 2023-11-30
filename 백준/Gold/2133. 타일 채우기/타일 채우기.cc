#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int dp[33];

int main()
{
    FASTIO();
    cin >> N;

    dp[2] = 3;
    int special = 0;

    for (int i = 3; i <= N; i++)
    {
        if (i % 2 == 0)
        {
            special += dp[i - 4] * 2;
            dp[i] = dp[i - 2] * dp[2] + special + 2;
        }
    }

    cout << dp[N] << "\n";
}