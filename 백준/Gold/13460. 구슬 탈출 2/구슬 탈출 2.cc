#include <iostream>
#include <queue>

using namespace std;

int N, M;

char myMap[11][11];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool visited[11][11][11][11];

struct ball
{
    int rx, ry;
    int bx, by;
    int cnt;

    ball(int rx, int ry, int bx, int by, int cnt) : rx(rx), ry(ry), bx(bx), by(by), cnt(cnt) {}
    ball() {}
};

void move(int &rx, int &ry, int &distance, int &d)
{
    while (myMap[rx + dx[d]][ry + dy[d]] != '#' && myMap[rx][ry] != 'O')
    {
        rx += dx[d];
        ry += dy[d];
        distance += 1;
    }
}

void bfs(int rx, int ry, int bx, int by)
{
    queue<ball> q;
    q.push(ball(rx, ry, bx, by, 0));
    visited[rx][ry][bx][by] = true;

    while (!q.empty())
    {
        int crx = q.front().rx;
        int cry = q.front().ry;
        int cbx = q.front().bx;
        int cby = q.front().by;

        int ccnt = q.front().cnt;

        q.pop();

        if (ccnt >= 10)
            break;

        for (int k = 0; k < 4; k++)
        {
            int nrx = crx, nry = cry, nbx = cbx, nby = cby;
            int rc = 0, bc = 0, ncnt = ccnt + 1;

            move(nrx, nry, rc, k);
            move(nbx, nby, bc, k);

            if (myMap[nbx][nby] == 'O')
                continue;

            if (myMap[nrx][nry] == 'O')
            {
                cout << ncnt << endl;
                return;
            }
            if (nrx == nbx && nry == nby)
            {
                if (rc > bc)
                {
                    nrx -= dx[k], nry -= dy[k];
                }
                else
                {
                    nbx -= dx[k], nby -= dy[k];
                }
            }

            if (visited[nrx][nry][nbx][nby])
            {
                continue;
            }
            else
            {
                visited[nrx][nry][nbx][nby] = true;
                q.push(ball(nrx, nry, nbx, nby, ncnt));
            }
        }
    }

    cout << -1 << endl;
}

int main()
{
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
                rx = i;
                ry = j;
            }
            else if (x == 'B')
            {
                bx = i;
                by = j;
            }
            myMap[i][j] = x;
        }
    }

    bfs(rx, ry, bx, by);

    return 0;
}