#include <iostream>
#include <string.h>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;

int myMap[55][55];
int dist[55][55];
bool visited[55][55];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int answer = 0;
bool infinite = false;

int dfs(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= M || myMap[x][y] == 0)
    {
        return 0;
    }
    if (visited[x][y])
    {
        cout << -1 << "\n";
        exit(0);
    }

    if (dist[x][y] != -1)
    {
        return dist[x][y];
    }

    visited[x][y] = true;
    dist[x][y] = 0;
    for (int k = 0; k < 4; k++)
    {
        int next_x = x + dx[k] * myMap[x][y];
        int next_y = y + dy[k] * myMap[x][y];
        dist[x][y] = max(dist[x][y], dfs(next_x, next_y) + 1);
    }

    visited[x][y] = false;
    return dist[x][y];
}

int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char x;
            cin >> x;

            if (x == 'H')
            {
                myMap[i][j] = 0;
            }
            else
            {
                myMap[i][j] = x - '0';
            }
        }
    }

    memset(dist, -1, sizeof(dist));
    cout << dfs(0, 0) << "\n";
}