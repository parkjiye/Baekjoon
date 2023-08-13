#include <iostream>
#include <string.h>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int H, W;
int myMap[501][501];
bool visited[501][501];

int dx[2] = {0, 0};
int dy[2] = {-1, 1};

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y) {}
};

int raindrop(p cur)
{
    queue<p> q;
    int total = 0;

    int left_wall = false;
    int right_wall = false;
    q.push(cur);
    total += 1;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 2; k++)
        {
            int next_y = cur.y + dy[k];

            if (next_y >= 0 && next_y < W)
            {
                if (myMap[cur.x][next_y] == 0 && !visited[cur.x][next_y])
                {
                    q.push(p(cur.x, next_y));
                    total += 1;
                    visited[cur.x][cur.y] = true;
                }
                else
                {
                    if (k == 0 && myMap[cur.x][next_y] == 1)
                    {
                        left_wall = true;
                    }
                    else if (k == 1 && myMap[cur.x][next_y] == 1)
                    {
                        right_wall = true;
                    }
                }
            }
        }
    }

    if (left_wall && right_wall)
    {
        return total;
    }
    else
    {
        return 0;
    }
}

int main()
{
    FASTIO();
    cin >> H >> W;

    memset(myMap, 0, sizeof(myMap));
    memset(visited, 0, sizeof(visited));

    int ans = 0;

    for (int i = 0; i < W; i++)
    {
        int x;
        cin >> x;

        for (int j = 0; j < x; j++)
        {
            myMap[H - 1 - j][i] = 1;
        }
    }

    for (int i = H - 1; i >= 0; i--)
    {
        for (int j = 0; j < W; j++)
        {
            if (myMap[i][j] == 0 && !visited[i][j])
            {
                ans += raindrop(p(i, j));
            }
        }
    }

    cout << ans << endl;
}