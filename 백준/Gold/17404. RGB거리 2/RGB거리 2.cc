#include <iostream>
#include <string.h>
#include <algorithm>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int rgb[1005][3];
int dp[1005][3];

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;

            rgb[i][j] = x;
        }
    }

    // R 선택
    memset(dp, 0, sizeof(dp));

    dp[1][0] = 1000005;
    dp[1][1] = rgb[0][0] + rgb[1][1];
    dp[1][2] = rgb[0][0] + rgb[1][2];

    for (int i = 2; i < N; i++)
    {
        dp[i][0] = rgb[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = rgb[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = rgb[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    int red = min(dp[N - 1][1], dp[N - 1][2]);

    // G 선택
    memset(dp, 0, sizeof(dp));

    dp[1][1] = 1000005;
    dp[1][0] = rgb[0][1] + rgb[1][0];
    dp[1][2] = rgb[0][1] + rgb[1][2];

    for (int i = 2; i < N; i++)
    {
        dp[i][0] = rgb[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = rgb[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = rgb[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    int green = min(dp[N - 1][0], dp[N - 1][2]);

    // B 선택
    memset(dp, 0, sizeof(dp));

    dp[1][2] = 1000005;
    dp[1][0] = rgb[0][2] + rgb[1][0];
    dp[1][1] = rgb[0][2] + rgb[1][1];

    for (int i = 2; i < N; i++)
    {
        dp[i][0] = rgb[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = rgb[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = rgb[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    int blue = min(dp[N - 1][0], dp[N - 1][1]);

    cout << min(red, min(green, blue)) << "\n";
}