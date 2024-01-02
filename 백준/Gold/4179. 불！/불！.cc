#include <iostream>
#include <queue>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int R, C;
char myMap[1005][1005];
bool visited[1005][1005];

struct p
{
    int x;
    int y;
    int t;

    p() {}
    p(int x, int y, int t) : x(x), y(y), t(t) {}
};

vector<p> fire;
p start;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs()
{
    queue<p> q;
    q.push(start);
    for (int i = 0; i < fire.size(); i++)
    {
        q.push(fire[i]);
    }
    memset(visited, 0, sizeof(visited));
    visited[start.x][start.y] = true;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        if (myMap[cur.x][cur.y] == '.')
        {
            for (int k = 0; k < 4; k++)
            {
                int next_x = cur.x + dx[k];
                int next_y = cur.y + dy[k];

                if (next_x < 0 || next_y < 0 || next_x >= R || next_y >= C)
                {
                    cout << cur.t + 1 << "\n";
                    return;
                }
                else if (myMap[next_x][next_y] == '.' && !visited[next_x][next_y])
                {
                    q.push(p(next_x, next_y, cur.t + 1));
                    visited[next_x][next_y] = true;
                }
            }
        }
        else if (myMap[cur.x][cur.y] == 'F')
        {
            for (int k = 0; k < 4; k++)
            {
                int next_x = cur.x + dx[k];
                int next_y = cur.y + dy[k];

                if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C && myMap[next_x][next_y] == '.')
                {
                    myMap[next_x][next_y] = 'F';
                    q.push(p(next_x, next_y, 0));
                }
            }
        }
    }

    cout << "IMPOSSIBLE"
         << "\n";
    return;
}

int main()
{
    FASTIO();
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < C; j++)
        {
            if (s[j] == 'J')
            {
                start = p(i, j, 0);
                myMap[i][j] = '.';
            }
            else if (s[j] == 'F')
            {
                fire.push_back(p(i, j, 0));
                myMap[i][j] = 'F';
            }
            else
            {
                myMap[i][j] = s[j];
            }
        }
    }

    bfs();
}