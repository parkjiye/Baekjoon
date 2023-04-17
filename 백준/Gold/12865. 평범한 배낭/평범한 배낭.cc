#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, K;
int weight[105];
int value[105];
int dp[105][100001];

int pick(int idx, int w)
{
    if (dp[idx][w] > 0)
        return dp[idx][w];

    if (idx == N)
    {
        return 0;
    }

    int isPicked = 0;
    int noPicked = 0;

    if (w + weight[idx] <= K)
    {
        isPicked = value[idx] + pick(idx + 1, w + weight[idx]);
    }

    noPicked = pick(idx + 1, w);

    return dp[idx][w] = max(isPicked, noPicked);
}

int main()
{
    FASTIO();

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int w, v;
        cin >> w >> v;

        weight[i] = w;
        value[i] = v;
    }

    cout << pick(0, 0) << endl;

    return 0;
}