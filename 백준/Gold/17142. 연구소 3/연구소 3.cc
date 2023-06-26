#include <iostream>
#include <queue>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct virus
{
    int x;
    int y;

    virus(int x, int y) : x(x), y(y) {}
    virus() {}
};

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y) {}
    p() {}
};

int myMap[55][55];
bool visited[55][55];
int dist[55][55];
vector<virus> v;
int path[55];
vector<virus> active;

int answer;

// 바이러스 선택
void bfs(int idx)
{
    if (idx == M)
    {
        queue<p> q;
        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        int local_max = 0;

        for (int i = 0; i < M; i++)
        {
            active[i] = v[path[i]];
            virus cur = active[i];
            q.push(p(cur.x, cur.y));
            visited[cur.x][cur.y] = true;
        }

        while (!q.empty())
        {
            p cur = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int next_x = cur.x + dx[k];
                int next_y = cur.y + dy[k];

                if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < N && !visited[next_x][next_y] && myMap[next_x][next_y] != 1)
                {
                    visited[next_x][next_y] = true;
                    q.push(p(next_x, next_y));
                    dist[next_x][next_y] = dist[cur.x][cur.y] + 1;
                }
            }
        }

        bool allspread = true;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (myMap[i][j] != 1 && !visited[i][j] && myMap[i][j] != 2)
                {
                    allspread = false;
                    break;
                }
            }
        }

        if (allspread)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (local_max < dist[i][j] && myMap[i][j] != 2)
                    {
                        local_max = dist[i][j];
                    }
                }
            }

            if (answer > local_max)
            {
                answer = local_max;
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (idx == 0 || path[idx - 1] < i)
        {
            path[idx] = i;
            bfs(idx + 1);
        }
    }
}

int main()
{
    FASTIO();
    cin >> N >> M;

    memset(myMap, 0, sizeof(myMap));
    memset(visited, 0, sizeof(visited));
    active.resize(M);

    answer = 30000;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = x;

            if (x == 2)
            {
                v.push_back(virus(i, j));
            }
        }
    }

    bfs(0);

    if (answer == 30000)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << answer << endl;
}