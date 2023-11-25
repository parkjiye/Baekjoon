#include <iostream>
#include <queue>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct p
{
    int x;
    int y;
    int t;

    p(int x, int y) : x(x), y(y) {}
    p(int x, int y, int t) : x(x), y(y), t(t) {}
    p() {}
};

p cockroach;
queue<p> water;
queue<p> ck;

int R, C;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char myMap[55][55];
bool visited[55][55];

void print()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << myMap[i][j] << " ";
        }
        cout << endl;
    }
}

queue<p> waterflow(queue<p> w)
{
    queue<p> temp;
    while (!w.empty())
    {
        p cur = w.front();
        w.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C && myMap[next_x][next_y] != 'D' && myMap[next_x][next_y] != 'X')
            {
                temp.push(p(next_x, next_y));
                myMap[next_x][next_y] = '*';
            }
        }
    }

    return temp;
}

int bfs()
{
    ck.push(cockroach);
    visited[cockroach.x][cockroach.y] = true;

    while (!ck.empty())
    {
        // water = waterflow(water);
        //  print();

        p cur = ck.front();
        ck.pop();

        if (myMap[cur.x][cur.y] == '*')
        {
            for (int k = 0; k < 4; k++)
            {
                int next_x = cur.x + dx[k];
                int next_y = cur.y + dy[k];

                if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C && myMap[next_x][next_y] != 'D' && myMap[next_x][next_y] != 'X' && myMap[next_x][next_y] != '*' && !visited[next_x][next_y])
                {
                    ck.push(p(next_x, next_y));
                    myMap[next_x][next_y] = '*';
                    visited[next_x][next_y] = true;
                }
            }
        }
        else
        {
            for (int k = 0; k < 4; k++)
            {
                int next_x = cur.x + dx[k];
                int next_y = cur.y + dy[k];

                if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C && myMap[next_x][next_y] != 'X' && myMap[next_x][next_y] != '*' && !visited[next_x][next_y])
                {
                    if (myMap[next_x][next_y] == 'D')
                    {
                        cout << cur.t + 1 << "\n";
                        return 0;
                    }
                    ck.push(p(next_x, next_y, cur.t + 1));
                    visited[next_x][next_y] = true;
                }
            }
        }
    }

    cout << "KAKTUS"
         << "\n";
    return 0;
}

int main()
{
    FASTIO();
    cin >> R >> C;

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < R; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++)
        {
            char c = s[j];

            if (c == 'S')
            {
                cockroach = p(i, j, 0);
                myMap[i][j] = '.';
            }
            else if (c == '*')
            {
                ck.push(p(i, j));
                myMap[i][j] = c;
                visited[i][j] = true;
            }
            else
            {
                myMap[i][j] = c;
            }
        }
    }

    bfs();
}