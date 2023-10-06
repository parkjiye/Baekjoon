#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int dp[1005];

    // SK - 0, CY - 1

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++)
    {
        dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
    }

    if (dp[N] % 2 == 0)
    {
        cout << "SK" << endl;
    }
    else
    {
        cout << "CY" << endl;
    }
}