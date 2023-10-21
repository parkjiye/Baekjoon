#include <iostream>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct p
{
    int x;
    int y;

    p() {}
    p(int x, int y) : x(x), y(y) {}
};

int R, C;
int cnt = 0;

int myMap[10005][505];
bool visited[10005][505];

int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};

bool dfs(p cur)
{
    if (cur.y == C - 1)
    {
        cnt += 1;
        return true;
    }

    myMap[cur.x][cur.y] = 1;

    for (int k = 0; k < 3; k++)
    {
        int next_x = cur.x + dx[k];
        int next_y = cur.y + dy[k];

        if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C && !myMap[next_x][next_y])
        {
            if (dfs(p(next_x, next_y)))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    FASTIO();
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char c;
            cin >> c;

            if (c == '.')
            {
                myMap[i][j] = 0;
            }
            else
            {
                myMap[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        if (!myMap[i][0])
        {
            dfs(p(i, 0));
        }
    }

    cout << cnt << "\n";
}