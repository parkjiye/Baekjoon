#include <iostream>
#include <queue>
#include <string.h>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
char myMap[12][12];
bool visited[12][12][12][12];

struct p
{
    int blue_x;
    int blue_y;
    int red_x;
    int red_y;
    int trn;

    p() {}
    p(int blue_x, int blue_y, int red_x, int red_y, int trn) : blue_x(blue_x), blue_y(blue_y), red_x(red_x), red_y(red_y), trn(trn) {}
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<p> q;

pair<int, int> move_ball(int x, int y, int d)
{
    while (1)
    {
        int next_x = x + dx[d];
        int next_y = y + dy[d];

        if (myMap[next_x][next_y] == '#')
        {
            return {x, y};
        }
        else if (myMap[next_x][next_y] == 'O')
        {
            return {next_x, next_y};
        }
        else
        {
            x = next_x;
            y = next_y;
        }
    }
}

int game(p start)
{
    memset(visited, 0, sizeof(visited));
    q.push(start);
    visited[start.blue_x][start.blue_y][start.red_x][start.red_y] = true;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            pair<int, int> r = move_ball(cur.red_x, cur.red_y, k);
            pair<int, int> b = move_ball(cur.blue_x, cur.blue_y, k);

            if (myMap[b.first][b.second] == 'O')
            {
                continue;
            }
            else if (myMap[r.first][r.second] == 'O')
            {
                return cur.trn + 1;
            }
            else if (r.first == b.first && r.second == b.second)
            {
                if (abs(cur.red_x - r.first) + abs(cur.red_y - r.second) > abs(cur.blue_x - b.first) + abs(cur.blue_y - b.second))
                {
                    r.first -= dx[k];
                    r.second -= dy[k];
                }
                else
                {
                    b.first -= dx[k];
                    b.second -= dy[k];
                }
            }

            if (!visited[b.first][b.second][r.first][r.second])
            {
                visited[b.first][b.second][r.first][r.second] = true;
                q.push(p(b.first, b.second, r.first, r.second, cur.trn + 1));
            }
        }
    }

    return -1;
}

int main()
{
    FASTIO();
    cin >> N >> M;

    p start;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char x;
            cin >> x;

            if (x == 'R')
            {
                start.red_x = i;
                start.red_y = j;
                myMap[i][j] = '.';
            }
            else if (x == 'B')
            {
                start.blue_x = i;
                start.blue_y = j;
                myMap[i][j] = '.';
            }
            else
            {
                myMap[i][j] = x;
            }
        }
    }

    start.trn = 0;

    cout << game(start) << "\n";
}