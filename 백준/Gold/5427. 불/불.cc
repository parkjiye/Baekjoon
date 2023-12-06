#include <iostream>
#include <string.h>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int T;
char myMap[1005][1005];
bool visited[1005][1005];

struct p
{
    int x;
    int y;
    int t;

    p(int x, int y) : x(x), y(y) {}
    p(int x, int y, int t) : x(x), y(y), t(t) {}
    p() {}
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(queue<p> q, int h, int w)
{
    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        if (myMap[cur.x][cur.y] == '.')
        {
            int cnt = 0;
            // cout << cur.x << " " << cur.y << "\n";

            for (int k = 0; k < 4; k++)
            {
                int next_x = cur.x + dx[k];
                int next_y = cur.y + dy[k];

                if (next_x < 0 || next_x >= h || next_y < 0 || next_y >= w)
                {
                    return cur.t + 1;
                }
                else if (myMap[next_x][next_y] == '.' && !visited[next_x][next_y])
                {
                    q.push(p(next_x, next_y, cur.t + 1));
                    visited[next_x][next_y] = true;
                }
                else
                {
                    cnt += 1;
                }
            }

            if (cnt == 4)
            {
                continue;
            }
        }

        if (myMap[cur.x][cur.y] == '*')
        {
            for (int k = 0; k < 4; k++)
            {
                int next_x = cur.x + dx[k];
                int next_y = cur.y + dy[k];

                if (next_x >= 0 && next_y >= 0 && next_x < h && next_y < w && myMap[next_x][next_y] != '*' && myMap[next_x][next_y] != '#')
                {
                    q.push(p(next_x, next_y));
                    myMap[next_x][next_y] = '*';
                    // visited[next_x][next_y] = true;
                }
            }
        }

        // for (int i = 0; i < h; i++)
        // {
        //     for (int j = 0; j < w; j++)
        //     {
        //         cout << myMap[i][j];
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }

    return -1;
}

int main()
{
    FASTIO();
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        memset(visited, 0, sizeof(visited));

        int w, h;
        cin >> w >> h;

        queue<p> q;
        vector<p> v;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                char x;
                cin >> x;

                if (x == '@')
                {
                    myMap[i][j] = '.';
                    q.push(p(i, j, 0));
                    visited[i][j] = true;
                }
                else if (x == '*')
                {
                    myMap[i][j] = x;
                    v.push_back(p(i, j));
                    // visited[i][j] = true;
                }
                else
                {
                    myMap[i][j] = x;
                }
            }
        }

        for (int i = 0; i < v.size(); i++)
        {
            q.push(v[i]);
        }

        int answer = bfs(q, h, w);

        if (answer == -1)
        {
            cout << "IMPOSSIBLE"
                 << "\n";
        }
        else
        {
            cout << answer << "\n";
        }
    }
}