#include <iostream>
#include <string.h>

using namespace std;

int dp[11][11];

int combination(int n, int k)
{

    if (dp[n][k] != 0)
    {
        return dp[n][k];
    }

    if (n == 0)
    {
        return 0;
    }
    else if (k == 1)
    {
        return dp[n][k] = n;
    }
    else if (k == 0)
    {
        return dp[n][k] = 1;
    }
    else
    {
        return dp[n][k] = combination(n - 1, k) + combination(n - 1, k - 1);
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    memset(dp, 0, sizeof(dp));

    cout << combination(N, K) << "\n";
}