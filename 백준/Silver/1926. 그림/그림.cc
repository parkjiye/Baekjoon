#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int myMap[505][505];
bool visited[505][505];

int n, m;

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y) {}
    p() {}
};

vector<int> v;

void bfs(p start)
{
    queue<p> q;
    int width = 0;
    q.push(start);
    visited[start.x][start.y] = true;
    width += 1;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && !visited[next_x][next_y] && myMap[next_x][next_y] == 1)
            {
                q.push(p(next_x, next_y));
                visited[next_x][next_y] = true;
                width += 1;
            }
        }
    }

    v.push_back(width);
}

int main()
{
    FASTIO();

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = x;
        }
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (myMap[i][j] == 1 && !visited[i][j])
            {
                bfs(p(i, j));
            }
        }
    }

    if (v.size() == 0)
    {
        cout << 0 << endl;
        cout << 0 << endl;
        return 0;
    }

    sort(v.begin(), v.end(), greater<>());

    cout << v.size() << endl;
    cout << v[0] << endl;
    return 0;
}