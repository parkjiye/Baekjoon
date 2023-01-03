#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int myMap[100][100][100];
int m, n, h;
int ripe_tomato;
int notripe_tomato;

int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, 0, -1, 1};
int dz[6] = {-1, 1, 0, 0, 0, 0};

struct p
{
    int x;
    int y;
    int z;
};

p make_p(int x, int y, int z)
{
    p temp;
    temp.x = x;
    temp.y = y;
    temp.z = z;
    return temp;
}

queue<p> q;

void bfs()
{
    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 6; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];
            int next_z = cur.z + dz[k];

            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && next_z >= 0 && next_z < h && myMap[next_z][next_x][next_y] == 0)
            {
                myMap[next_z][next_x][next_y] = myMap[cur.z][cur.x][cur.y] + 1;
                q.push(make_p(next_x, next_y, next_z));
            }
        }
    }
}

int main()
{
    cin >> m >> n >> h;
    memset(myMap, 0, sizeof(myMap));

    ripe_tomato = 0;
    notripe_tomato = 0;

    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                int num;
                cin >> num;
                myMap[k][i][j] = num;

                if (myMap[k][i][j] == 1)
                {
                    ripe_tomato += 1;
                    q.push(make_p(i, j, k));
                }
                else if (myMap[k][i][j] == 0)
                {
                    notripe_tomato += 1;
                }
            }
        }
    }

    if (notripe_tomato == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    bfs();

    int answer = 0;

    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (myMap[k][i][j] == 0)
                {
                    cout << -1 << endl;
                    return 0;
                }

                if (answer < myMap[k][i][j])
                {
                    answer = myMap[k][i][j];
                }

            }
        }
    }

    cout << answer - 1 << endl;
}