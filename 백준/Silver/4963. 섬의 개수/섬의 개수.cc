#include <iostream>
#include <string.h>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int T;
int myMap[55][55];
bool visited[55][55];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

struct p
{
    int x;
    int y;

    p() {}
    p(int x, int y) : x(x), y(y) {}
};

void bfs(p start, int w, int h)
{
    visited[start.x][start.y] = true;
    queue<p> q;
    q.push(start);

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 8; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_y >= 0 && next_x < h && next_y < w && myMap[next_x][next_y] == 1 && !visited[next_x][next_y])
            {
                q.push(p(next_x, next_y));
                visited[next_x][next_y] = true;
            }
        }
    }
}

int main()
{
    FASTIO();

    while (1)
    {
        int w, h;
        cin >> w >> h;

        if (w == 0 && h == 0)
        {
            return 0;
        }

        memset(visited, 0, sizeof(visited));
        memset(myMap, 0, sizeof(myMap));

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int x;
                cin >> x;

                myMap[i][j] = x;
            }
        }

        int cnt = 0;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (myMap[i][j] == 1 && !visited[i][j])
                {
                    bfs(p(i, j), w, h);
                    cnt += 1;
                }
            }
        }

        cout << cnt << "\n";
    }
}