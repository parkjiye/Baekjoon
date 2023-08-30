#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int nums[100005];
int dp[100005];

int main()
{
    FASTIO();

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        nums[i] = x;
    }

    dp[0] = nums[0];

    for (int i = 1; i < N; i++)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    }

    int ans = -100000000;

    for (int i = 0; i < N; i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
        }
    }

    cout << ans << endl;
}