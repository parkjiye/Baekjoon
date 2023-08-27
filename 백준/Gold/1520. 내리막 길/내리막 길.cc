#include <iostream>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int M, N;

int myMap[505][505];
int dp[505][505];
bool visited[505][505] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y){};
    p(){};
};

int dfs(p cur)
{
    if (dp[cur.x][cur.y] == -1)
    {
        dp[cur.x][cur.y] = 0;

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];
            if (next_x >= 0 && next_y >= 0 && next_x < M && next_y < N && myMap[cur.x][cur.y] < myMap[next_x][next_y])
            {
                dp[cur.x][cur.y] += dfs(p(next_x, next_y));
            }
        }
    }

    return dp[cur.x][cur.y];
}

int main()
{
    FASTIO();
    cin >> M >> N;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = x;
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 1;

    cout << dfs(p(M - 1, N - 1)) << endl;
}