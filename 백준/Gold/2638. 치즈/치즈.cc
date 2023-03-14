#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

int N, M;
int myMap[105][105];
bool visited[105][105];
bool outline[105][105];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct p
{
    int x;
    int y;
};

p make_p(int x, int y)
{
    p temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

void checkoutline()
{
    queue<p> q;
    q.push(make_p(0, 0));
    visited[0][0] = true;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && !visited[next_x][next_y])
            {
                if (myMap[next_x][next_y] == 0)
                {
                    q.push(make_p(next_x, next_y));
                    visited[next_x][next_y] = true;
                    outline[next_x][next_y] = true;
                }
                else
                {
                    visited[next_x][next_y] = true;
                    outline[next_x][next_y] = true;
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    int cheese = 0;
    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = x;

            if (x == 1)
                cheese += 1;
        }
    }

    // for (int l = 0; l < 4; l++)
    while (cheese)
    {
        memset(visited, 0, sizeof(visited));
        memset(outline, 0, sizeof(outline));
        vector<p> erase;

        checkoutline();

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (outline[i][j] && myMap[i][j] == 1)
                {
                    int out = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int next_x = i + dx[k];
                        int next_y = j + dy[k];

                        if (myMap[next_x][next_y] == 0 && outline[next_x][next_y])
                            out += 1;
                    }

                    if (out >= 2)
                    {
                        erase.push_back(make_p(i, j));
                    }
                }
            }
        }

        for (int i = 0; i < erase.size(); i++)
        {
            p cur = erase[i];

            myMap[cur.x][cur.y] = 0;
            cheese--;
        }

        answer += 1;
    }

    cout << answer << endl;

    return 0;
}