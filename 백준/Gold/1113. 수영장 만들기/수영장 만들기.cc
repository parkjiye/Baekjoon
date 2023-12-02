#include <iostream>
#include <queue>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int myMap[50][50];
int pool[50][50];
bool visited[50][50];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct p
{
    int x;
    int y;

    p() {}
    p(int x, int y) : x(x), y(y) {}
};

int ans = 0;

void bfs(p start, int d)
{
    queue<p> q;
    q.push(start);
    visited[start.x][start.y] = true;

    int temp = 1;
    bool surrounded = true;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
            {
                surrounded = false;
                continue;
            }

            if (!visited[next_x][next_y] && myMap[next_x][next_y] <= d)
            {
                temp += 1;
                visited[next_x][next_y] = true;
                q.push(p(next_x, next_y));
            }
        }
    }

    if (surrounded)
    {
        ans += temp;
    }
    else
    {
        return;
    }
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
            myMap[i][j] = s[j] - '0';
        }
    }

    for (int h = 1; h < 9; h++)
    {
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!visited[i][j] && myMap[i][j] <= h)
                {
                    bfs(p(i, j), h);
                }
            }
        }
    }

    cout << ans << "\n";
}