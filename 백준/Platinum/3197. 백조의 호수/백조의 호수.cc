#include <iostream>
#include <queue>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int R, C;
int myMap[1505][1505];
bool visited[1505][1505];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct p
{
    int x;
    int y;
    int d;

    p(int x, int y, int d) : x(x), y(y), d(d) {}
    p() {}
};

struct comp
{
    bool operator()(p a, p b)
    {
        if (a.d > b.d)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    FASTIO();
    cin >> R >> C;
    memset(visited, 0, sizeof(visited));

    p swan1 = p(0, 0, -1);
    p swan2 = p(0, 0, -1);

    for (int i = 0; i < R; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < C; j++)
        {
            if (s[j] == '.')
            {
                myMap[i][j] = 0;
            }
            else if (s[j] == 'L')
            {
                myMap[i][j] = -1;

                if (swan1.d == -1)
                {
                    swan1 = p(i, j, 0);
                }
                else
                {
                    swan2 = p(i, j, 0);
                }
            }
            else
            {
                myMap[i][j] = -2;
            }
        }
    }

    queue<p> q;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (myMap[i][j] == 0 || myMap[i][j] == -1)
            {
                for (int k = 0; k < 4; k++)
                {
                    int next_x = i + dx[k];
                    int next_y = j + dy[k];

                    if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C && myMap[next_x][next_y] == -2 && !visited[next_x][next_y])
                    {
                        q.push(p(next_x, next_y, 1));
                        myMap[next_x][next_y] = 1;
                        visited[next_x][next_y] = true;
                    }
                }
            }
        }
    }

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C && myMap[next_x][next_y] == -2 && !visited[next_x][next_y])
            {
                q.push(p(next_x, next_y, cur.d + 1));
                myMap[next_x][next_y] = cur.d + 1;
                visited[next_x][next_y] = true;
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    priority_queue<p, vector<p>, comp> pq;
    pq.push(swan1);
    visited[swan1.x][swan1.y] = true;

    int ans = 0;

    while (!pq.empty())
    {
        p cur = pq.top();
        pq.pop();

        if (cur.d > ans)
        {
            ans = cur.d;
        }

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C && !visited[next_x][next_y])
            {
                if (next_x == swan2.x && next_y == swan2.y)
                {
                    cout << ans << endl;
                    return 0;
                }
                else
                {
                    pq.push(p(next_x, next_y, myMap[next_x][next_y]));

                    visited[next_x][next_y] = true;
                }
            }
        }
    }
}