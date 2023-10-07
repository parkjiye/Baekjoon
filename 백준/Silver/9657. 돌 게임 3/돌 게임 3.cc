#include <iostream>

using namespace std;

int dp[1005];

int main()
{
    int N;
    cin >> N;

    dp[0] = 0;
    dp[1] = 1;
    dp[3] = 1;
    dp[4] = 1;

    for (int i = 4; i <= N; i++)
    {
        if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0)
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = 0;
        }
    }

    if (dp[N] == 1)
    {
        cout << "SK" << endl;
    }
    else
    {
        cout << "CY" << endl;
    }
}
