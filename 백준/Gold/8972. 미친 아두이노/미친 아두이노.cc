#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <string>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct board
{
    bool jongsu;
    int crazy;

    board() {}
    board(bool jongsu, int crazy) : jongsu(jongsu), crazy(crazy) {}
};

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y){};
    p() {}
};

int R, C;
board myMap[105][105];
bool visited[105][105];
int dist[105][105];
board temp[105][105];

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int tx[4] = {1, -1, 0, 0};
int ty[4] = {0, 0, -1, 1};

vector<int> v;
p cur;

int main()
{
    FASTIO();
    cin >> R >> C;

    bool lose = false;
    int ans;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char x;
            cin >> x;

            if (x == '.')
            {
                myMap[i][j] = board(false, 0);
            }
            else if (x == 'I')
            {
                myMap[i][j] = board(true, 0);
                cur = p(i, j);
            }
            else
            {
                myMap[i][j] = board(false, 1);
            }
        }
    }

    string sen;
    cin >> sen;

    for (int i = 0; i < sen.length(); i++)
    {
        v.push_back((int)sen[i] - 48);
    }

    for (int t = 0; t < v.size(); t++)
    {
        // 종수가 이동
        int dir;

        if (v[t] == 1)
        {
            dir = 0;
        }
        else if (v[t] == 2)
        {
            dir = 1;
        }
        else if (v[t] == 3)
        {
            dir = 2;
        }
        else if (v[t] == 4)
        {
            dir = 7;
        }
        else if (v[t] == 6)
        {
            dir = 3;
        }
        else if (v[t] == 7)
        {
            dir = 6;
        }
        else if (v[t] == 8)
        {
            dir = 5;
        }
        else if (v[t] == 9)
        {
            dir = 4;
        }

        if (v[t] != 5)
        {
            int next_x = cur.x + dx[dir];
            int next_y = cur.y + dy[dir];

            if (myMap[next_x][next_y].crazy > 0)
            {
                lose = true;
                ans = t + 1;
                break;
            }
            else
            {
                myMap[cur.x][cur.y].jongsu = false;
                myMap[next_x][next_y].jongsu = true;
                cur = p(next_x, next_y);
            }
        }

        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));

        queue<p> q;
        q.push(cur);
        visited[cur.x][cur.y] = true;
        dist[cur.x][cur.y] = 0;

        while (!q.empty())
        {
            p now = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nx = now.x + tx[k];
                int ny = now.y + ty[k];

                if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[nx][ny])
                {
                    q.push(p(nx, ny));
                    dist[nx][ny] = dist[now.x][now.y] + 1;
                    visited[nx][ny] = true;
                }
            }
        }

        memcpy(temp, myMap, sizeof(myMap));

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (myMap[i][j].crazy > 0)
                {
                    int d = 1000;
                    int w;

                    for (int k = 0; k < 8; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (nx >= 0 && nx < R && ny >= 0 && ny < C)
                        {
                            if (dist[nx][ny] < d)
                            {
                                d = dist[nx][ny];
                                w = k;
                            }
                        }
                    }

                    int rx = i + dx[w];
                    int ry = j + dy[w];

                    if (myMap[rx][ry].jongsu)
                    {
                        lose = true;
                        ans = t + 1;
                        break;
                    }

                    temp[i][j].crazy -= 1;
                    temp[rx][ry].crazy += 1;
                }
            }

            if (lose)
            {
                break;
            }
        }

        if (lose)
        {
            break;
        }

        memcpy(myMap, temp, sizeof(temp));

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (myMap[i][j].crazy > 1)
                {
                    myMap[i][j].crazy = 0;
                }
            }
        }
    }

    if (lose)
    {
        cout << "kraj " << ans << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (myMap[i][j].jongsu)
                {
                    cout << "I";
                }
                else if (myMap[i][j].crazy > 0)
                {
                    cout << "R";
                }
                else
                {
                    cout << ".";
                }
            }
            cout << "\n";
        }
    }
}