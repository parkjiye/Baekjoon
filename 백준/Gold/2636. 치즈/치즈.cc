#include <iostream>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int myMap[101][101];
bool visited[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int M, N;
int cheese;

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
};

void bfs(p start)
{
    queue<p> q;
    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N && !visited[next_x][next_y])
            {
                if (myMap[next_x][next_y] == 1)
                {
                    myMap[next_x][next_y] = 0;
                    visited[next_x][next_y] = true;
                    cheese--;
                }
                else
                {
                    q.push(make_p(next_x, next_y));
                    visited[next_x][next_y] = true;
                }
            }
        }
    }
}

int main()
{
    cin >> M >> N;

    cheese = 0;

    int answer = 0;

    vector<int> cheese_stat;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;
            myMap[i][j] = x;
            if (x)
                cheese += 1;
        }
    }

    int origin = cheese;

    while (cheese != 0)
    {
        memset(visited, 0, sizeof(visited));
        bfs(make_p(0, 0));
        cheese_stat.push_back(cheese);
        answer += 1;
    }

    cout << answer << endl;

    if (answer == 1)
        cout << origin << endl;
    else
        cout << cheese_stat[cheese_stat.size() - 2] << endl;
}