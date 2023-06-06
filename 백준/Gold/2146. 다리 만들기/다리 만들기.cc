#include <iostream>
#include <string.h>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int myMap[105][105];
int dist[105][105];
bool visited[105][105];

int N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y) {}
    p() {}
};

void make_island(p start, int island)
{
    queue<p> q;
    q.push(start);
    myMap[start.x][start.y] = island;
    visited[start.x][start.y] = true;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < N && myMap[next_x][next_y] && !visited[next_x][next_y])
            {
                q.push(p(next_x, next_y));
                visited[next_x][next_y] = true;
                myMap[next_x][next_y] = island;
            }
        }
    }
}

int bfs(p start)
{
    queue<p> q;
    q.push(start);
    dist[start.x][start.y] = 0;
    visited[start.x][start.y] = true;
    int island = myMap[start.x][start.y];

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < N && !visited[next_x][next_y])
            {
                if (myMap[next_x][next_y] != 0 && myMap[next_x][next_y] != island)
                {
                    return dist[cur.x][cur.y];
                }
                else if (myMap[next_x][next_y] == 0)
                {
                    q.push(p(next_x, next_y));
                    visited[next_x][next_y] = true;
                    dist[next_x][next_y] = dist[cur.x][cur.y] + 1;
                }
            }
        }
    }

    return 0;
}

int main()
{
    FASTIO();
    cin >> N;

    int answer = 10000;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = x;
        }
    }

    int island = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (myMap[i][j] == 1 && !visited[i][j])
            {
                make_island(p(i, j), island);
                island += 1;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (myMap[i][j] != 0)
            {
                memset(visited, 0, sizeof(visited));
                memset(dist, 0, sizeof(dist));

                int temp = bfs(p(i, j));

                if (temp != 0 && answer > temp)
                {
                    answer = temp;
                }
            }
        }
    }

    cout << answer << endl;
    return 0;
}