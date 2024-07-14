/*
    뭔가 플로이드 와샬을 써야할 것 같은데
    가로 세로 각각 50이하 > 2500
*/

#include <iostream>
#include <queue>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
char myMap[55][55];
bool visited[55][55];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct p
{
    int x;
    int y;
    int d;

    p() {}
    p(int x, int y, int d) : x(x), y(y), d(d) {}
};

int bfs(p start)
{
    memset(visited, 0, sizeof(visited));
    queue<p> q;
    q.push(start);
    visited[start.x][start.y] = true;

    p cur;

    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && !visited[next_x][next_y] && myMap[next_x][next_y] == 'L')
            {
                q.push(p(next_x, next_y, cur.d + 1));
                visited[next_x][next_y] = true;
            }
        }
    }

    return cur.d;
}

int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++)
        {
            myMap[i][j] = s[j];
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (myMap[i][j] == 'L')
            {
                int dist = bfs(p(i, j, 0));

                if (dist > ans)
                {
                    ans = dist;
                }
            }
        }
    }

    cout << ans << "\n";
}