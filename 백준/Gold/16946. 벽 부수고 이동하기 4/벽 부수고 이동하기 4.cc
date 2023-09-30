#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <map>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int myMap[1005][1005];
int idx[1005][1005];
bool visited[1005][1005];
bool visited_2[1005][1005];

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y) {}
    p() {}
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(p start, int id)
{
    memset(visited, 0, sizeof(visited));

    queue<p> q;
    int total = 1;
    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && myMap[next_x][next_y] == 0 && !visited[next_x][next_y])
            {
                total += 1;
                visited[next_x][next_y] = true;
                q.push(p(next_x, next_y));
            }
        }
    }

    q.push(start);
    visited_2[start.x][start.y] = true;
    myMap[start.x][start.y] = total;
    idx[start.x][start.y] = id;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && myMap[next_x][next_y] == 0 && !visited_2[next_x][next_y])
            {
                myMap[next_x][next_y] = total;
                visited_2[next_x][next_y] = true;
                idx[next_x][next_y] = id;
                q.push(p(next_x, next_y));
            }
        }
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
            myMap[i][j] *= -1;
        }
    }

    int section = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (myMap[i][j] == 0 && !visited_2[i][j])
            {
                bfs(p(i, j), section);
                section += 1;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (myMap[i][j] != -1)
            {
                cout << 0;
            }
            else
            {
                int ans = 1;

                map<int, int> m;

                for (int k = 0; k < 4; k++)
                {
                    int next_x = i + dx[k];
                    int next_y = j + dy[k];

                    if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && myMap[next_x][next_y] != -1)
                    {
                        m.insert({idx[next_x][next_y], myMap[next_x][next_y]});
                    }
                }

                for (auto it = m.begin(); it != m.end(); it++)
                {
                    ans += it->second;
                }

                cout << ans % 10;
            }
        }
        cout << "\n";
    }
}