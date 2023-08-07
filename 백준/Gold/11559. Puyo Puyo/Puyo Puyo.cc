#include <iostream>
#include <string.h>
#include <queue>
#include <vector>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int myMap[15][10];
bool visited[15][10];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y) {}
    p() {}
};

int bfs(p start, int color)
{

    bool temp[15][10];
    memcpy(temp, visited, sizeof(visited));

    queue<p> q;

    visited[start.x][start.y] = true;
    q.push(start);

    int cnt = 1;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_x < 12 && next_y >= 0 && next_y < 6 && myMap[next_x][next_y] == color && !visited[next_x][next_y])
            {
                q.push(p(next_x, next_y));
                visited[next_x][next_y] = true;
                cnt += 1;
            }
        }
    }

    if (cnt >= 4)
    {
        q.push(start);
        myMap[start.x][start.y] = 0;
        temp[start.x][start.y] = true;

        while (!q.empty())
        {
            p cur = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int next_x = cur.x + dx[k];
                int next_y = cur.y + dy[k];

                if (next_x >= 0 && next_x < 12 && next_y >= 0 && next_y < 6 && myMap[next_x][next_y] == color && !temp[next_x][next_y])
                {
                    q.push(p(next_x, next_y));
                    myMap[next_x][next_y] = 0;
                    temp[start.x][start.y] = true;
                }
            }
        }

        return true;
    }
    else
    {
        return false;
    }
}

// R 1 G 2 B 3 P 4 Y 5
int main()
{
    FASTIO();

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            char x;
            cin >> x;

            switch (x)
            {
            case '.':
                myMap[i][j] = 0;
                break;
            case 'R':
                myMap[i][j] = 1;
                break;
            case 'G':
                myMap[i][j] = 2;
                break;
            case 'B':
                myMap[i][j] = 3;
                break;
            case 'P':
                myMap[i][j] = 4;
                break;
            case 'Y':
                myMap[i][j] = 5;
                break;
            }
        }
    }

    int ans = 0;

    while (1)
    {

        bool explode = false;

        for (int i = 0; i < 6; i++)
        {
            vector<int> v;
            for (int j = 11; j >= 0; j--)
            {
                if (myMap[j][i] != 0)
                {
                    v.push_back(myMap[j][i]);
                    myMap[j][i] = 0;
                }
            }

            for (int j = 0; j < v.size(); j++)
            {
                myMap[11 - j][i] = v[j];
            }
        }

        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (myMap[i][j] != 0 && !visited[i][j])
                {
                    if (bfs(p(i, j), myMap[i][j]))
                    {
                        explode = true;
                    }
                }
            }
        }

        if (explode)
        {
            ans += 1;
        }
        else
        {
            cout << ans << endl;
            return 0;
        }
    }
}