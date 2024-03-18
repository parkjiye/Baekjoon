#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char myMap[105][105];
int dp[105][105];

int N, M;
struct p
{
    int x;
    int y;

    p() {}
    p(int x, int y) : x(x), y(y) {}
};

void bfs()
{
    queue<p> q;
    q.push(p(0, 0));
    dp[0][0] = 0;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N)
            {
                if (myMap[next_x][next_y] == '1')
                {
                    if (dp[cur.x][cur.y] + 1 < dp[next_x][next_y])
                    {
                        q.push(p(next_x, next_y));
                        dp[next_x][next_y] = dp[cur.x][cur.y] + 1;
                    }
                }
                else
                {
                    if (dp[cur.x][cur.y] < dp[next_x][next_y])
                    {
                        q.push(p(next_x, next_y));
                        dp[next_x][next_y] = dp[cur.x][cur.y];
                    }
                }
            }
        }
    }
    return;
}

int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++)
        {
            myMap[i][j] = s[j];
            dp[i][j] = INT16_MAX;
        }
    }

    bfs();

    cout << dp[M - 1][N - 1] << "\n";
}