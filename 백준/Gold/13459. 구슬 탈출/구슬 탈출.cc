#include <iostream>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct ball
{
    int rx;
    int ry;
    int bx;
    int by;
    int rnd;

    ball(int rx, int ry, int bx, int by, int rnd) : rx(rx), ry(ry), bx(bx), by(by), rnd(rnd) {}
    ball() {}
};

struct p
{
    int x;
    int y;
    int d;

    p(int x, int y, int d) : x(x), y(y), d(d) {}
    p() {}
};

int N, M;
char myMap[12][12];
bool visited[12][12][12][12];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void print(ball cur)
{
    cout << cur.rnd << " " << cur.rx << " " << cur.ry << " " << cur.bx << " " << cur.by << "\n";
}

p move(int x, int y, int d)
{
    int dist = 0;

    while (myMap[x][y] != 'O' && myMap[x + dx[d]][y + dy[d]] != '#')
    {
        x += dx[d];
        y += dy[d];
        dist += 1;
    }

    return p(x, y, dist);
}

bool possible = false;

void bfs(ball start)
{
    queue<ball> q;
    q.push(start);
    visited[start.rx][start.ry][start.bx][start.by] = true;

    while (!q.empty())
    {
        ball cur = q.front();
        q.pop();

        if (cur.rnd == 10)
        {
            break;
        }
        else
        {
            for (int k = 0; k < 4; k++)
            {
                p red = move(cur.rx, cur.ry, k);
                p blue = move(cur.bx, cur.by, k);

                if (myMap[blue.x][blue.y] == 'O')
                {
                    continue;
                }

                if (myMap[red.x][red.y] == 'O')
                {
                    cout << 1 << "\n";
                    return;
                }

                if (red.x == blue.x && red.y == blue.y)
                {
                    if (red.d < blue.d)
                    {
                        blue.x -= dx[k];
                        blue.y -= dy[k];
                    }
                    else
                    {
                        red.x -= dx[k];
                        red.y -= dy[k];
                    }
                }

                if (visited[red.x][red.y][blue.x][blue.y])
                {
                    continue;
                }
                else
                {
                    visited[red.x][red.y][blue.x][blue.y] = true;
                    q.push(ball(red.x, red.y, blue.x, blue.y, cur.rnd + 1));
                }
            }
        }
    }

    cout << 0 << "\n";
}

int main()
{
    FASTIO();
    cin >> N >> M;

    int rx, ry, bx, by;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char x;
            cin >> x;

            if (x == 'R')
            {
                rx = i, ry = j;
                myMap[i][j] = '.';
            }
            else if (x == 'B')
            {
                bx = i, by = j;
                myMap[i][j] = '.';
            }
            else
            {
                myMap[i][j] = x;
            }
        }
    }

    bfs(ball(rx, ry, bx, by, 0));

    return 0;
}