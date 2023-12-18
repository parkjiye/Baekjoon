#include <iostream>
#include <string.h>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
char myMap[12][12];
bool visited[12][12][12][12];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dd[4] = {'U', 'D', 'L', 'R'};

struct p
{
    int blue_x;
    int blue_y;
    int red_x;
    int red_y;
    vector<int> dir;

    p() {}
    p(int blue_x, int blue_y, int red_x, int red_y, vector<int> dir) : blue_x(blue_x), blue_y(blue_y), red_x(red_x), red_y(red_y), dir(dir) {}
};

pair<int, int> move(int x, int y, int d)
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

void game(p start)
{
    queue<p> q;
    q.push(start);
    visited[start.red_x][start.red_y][start.blue_x][start.blue_y] = true;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        if (cur.dir.size() == 10)
        {
            cout << -1 << "\n";
            return;
        }

        for (int k = 0; k < 4; k++)
        {
            pair<int, int> r = move(cur.red_x, cur.red_y, k);
            pair<int, int> b = move(cur.blue_x, cur.blue_y, k);

            if (myMap[b.first][b.second] == 'O')
            {
                continue;
            }
            else if (myMap[r.first][r.second] == 'O')
            {
                cout << cur.dir.size() + 1 << "\n";
                for (int i = 0; i < cur.dir.size(); i++)
                {
                    cout << dd[cur.dir[i]];
                }
                cout << dd[k] << "\n";
                return;
            }
            else if (r.first == b.first && r.second == b.second)
            {
                if (abs(r.first - cur.red_x) + abs(r.second - cur.red_y) > abs(b.first - cur.blue_x) + abs(b.second - cur.blue_y))
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

            if (!visited[r.first][r.second][b.first][b.second])
            {
                vector<int> v = cur.dir;
                v.push_back(k);

                q.push(p(b.first, b.second, r.first, r.second, v));
                visited[r.first][r.second][b.first][b.second] = true;
            }
        }
    }

    cout << -1 << "\n";
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

    game(start);
}