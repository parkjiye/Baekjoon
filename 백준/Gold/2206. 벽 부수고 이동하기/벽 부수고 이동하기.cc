#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int myMap[1001][1001];
bool visited[1001][1001][2];
int dist[1001][1001][2];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int N, M;

struct p
{
    int x;
    int y;
    int pushed;
};

p make_p(int x, int y, int pushed)
{
    p temp;
    temp.x = x;
    temp.y = y;
    temp.pushed = pushed;
    return temp;
}

int bfs()
{
    queue<p> q;
    q.push(make_p(0, 0, 0));
    visited[0][0][0] = true;
    dist[0][0][0] = 1;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && !visited[next_x][next_y][cur.pushed])
            {
                if (next_x == N - 1 && next_y == M - 1)
                {
                    dist[next_x][next_y][cur.pushed] = dist[cur.x][cur.y][cur.pushed] + 1;
                    return dist[N - 1][M - 1][cur.pushed];
                }

                if (myMap[next_x][next_y] == 0)
                {
                    q.push(make_p(next_x, next_y, cur.pushed));
                    visited[next_x][next_y][cur.pushed] = true;
                    dist[next_x][next_y][cur.pushed] = dist[cur.x][cur.y][cur.pushed] + 1;
                }
                else
                {
                    if (!cur.pushed)
                    {
                        q.push(make_p(next_x, next_y, true));
                        visited[next_x][next_y][1] = true;
                        dist[next_x][next_y][1] = dist[cur.x][cur.y][cur.pushed] + 1;
                    }
                }
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int answer = INT16_MAX;

    for (int i = 0; i < N; i++)
    {
        string sen;
        cin >> sen;
        for (int j = 0; j < M; j++)
        {
            myMap[i][j] = sen[j] - '0';
        }
    }

    if (N == 1 && M == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    cout << bfs() << endl;

    return 0;
}