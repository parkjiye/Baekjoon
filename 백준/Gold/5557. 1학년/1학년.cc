#include <iostream>
#include <vector>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
vector<int> v;
long long int dp[25][105];

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }

    dp[v[0]][0] = 1;

    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (dp[j][i - 1] >= 1)
            {
                int a = j + v[i];
                int b = j - v[i];

                if (a <= 20)
                {
                    dp[a][i] += dp[j][i - 1];
                }
                if (b >= 0)
                {
                    dp[b][i] += dp[j][i - 1];
                }
            }
        }
    }

    cout << dp[v[v.size() - 1]][N - 2] << "\n";

}