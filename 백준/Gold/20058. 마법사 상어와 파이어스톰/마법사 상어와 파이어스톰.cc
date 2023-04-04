#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int myMap[65][65];
int temp[65][65];
int N, Q;
vector<int> spell;
bool visited[65][65];

int width;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int x, int y)
{
    queue<pair<int, int>> q;
    int size = 1;

    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;

        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur_x + dx[k];
            int next_y = cur_y + dy[k];

            if (next_x >= 0 && next_x < width && next_y >= 0 && next_y < width && myMap[next_x][next_y] != 0 && !visited[next_x][next_y])
            {
                q.push({next_x, next_y});
                visited[next_x][next_y] = true;
                size += 1;
            }
        }
    }

    return size;
}

void rotate_ice(int s, int n, int x, int y)
{
    int w = pow(2, n);

    if (n == s)
    {
        for (int i = x; i < x + w; i++)
        {
            for (int j = y; j < y + w; j++)
            {
                temp[i][j] = myMap[y + w - 1 - j + x][y + i - x];
            }
        }
    }
    else
    {
        int nw = pow(2, n - 1);
        rotate_ice(s, n - 1, x, y);
        rotate_ice(s, n - 1, x, y + nw);
        rotate_ice(s, n - 1, x + nw, y);
        rotate_ice(s, n - 1, x + nw, y + nw);
    }
}

int main()
{
    FASTIO();

    cin >> N >> Q;

    width = pow(2, N);

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int x;
            cin >> x;
            myMap[i][j] = x;
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int x;
        cin >> x;
        spell.push_back(x);
    }

    for (int i = 0; i < spell.size(); i++)
    {

        memcpy(temp, myMap, sizeof(myMap));

        rotate_ice(spell[i], N, 0, 0);

        memcpy(myMap, temp, sizeof(temp));

        int melt_ice[65][65];
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < width; j++)
            {
                melt_ice[i][j] = myMap[i][j];
            }
        }

        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (myMap[i][j])
                {
                    int ice = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int next_x = i + dx[k];
                        int next_y = j + dy[k];

                        if (next_x >= 0 && next_x < width && next_y >= 0 && next_y < width && myMap[next_x][next_y] != 0)
                        {
                            ice += 1;
                        }
                    }

                    if (ice < 3)
                    {
                        melt_ice[i][j] -= 1;
                    }
                }
            }
        }

        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < width; j++)
            {
                myMap[i][j] = melt_ice[i][j];
            }
        }
    }

    int sum = 0;
    int answer = 0;

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sum += myMap[i][j];

            if (!visited[i][j] && myMap[i][j] != 0)
            {
                int tmp = bfs(i, j);

                if (answer < tmp)
                {
                    answer = tmp;
                }
            }
        }
    }
    cout << sum << endl;
    cout << answer << endl;

    return 0;
}