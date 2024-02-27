#include <iostream>
#include <vector>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_INT 10000005;
using namespace std;

int N, M;
int sum = 0;
int dp[105][10005];

struct p
{
    int m;
    int c;

    p() {}
    p(int m, int c) : m(m), c(c) {}
};

vector<p> v;

int app(int idx, int cost)
{

    if (dp[idx][cost] != -1)
    {
        return dp[idx][cost];
    }

    if (idx == N)
    {
        dp[idx][cost] = 0;
        return 0;
    }

    if (cost < v[idx].c)
    {
        return dp[idx][cost] = app(idx + 1, cost);
    }
    else
    {
        return dp[idx][cost] = max(app(idx + 1, cost), app(idx + 1, cost - v[idx].c) + v[idx].m);
    }
}

int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 10000; j++)
        {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        v.push_back(p(x, 0));
    }

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        v[i].c = x;
    }

    app(0, 0);

    for (int i = 0; i <= 10000; i++)
    {
        int cost = app(0, i);

        if (cost >= M)
        {
            cout << i << "\n";
            break;
        }
    }
}