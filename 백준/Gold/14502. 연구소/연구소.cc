#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

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

int N, M;
int myMap[9][9];
bool visited[9][9];

int answer;

vector<p> space;
vector<p> virus;
queue<p> q;
int path[64 * 64 * 64];

void bfs()
{
    for (int i = 0; i < virus.size(); i++)
    {
        q.push(virus[i]);
        myMap[virus[i].x][virus[i].y] = true;
        visited[virus[i].x][virus[i].y] = true;
    }

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && !visited[next_x][next_y] && myMap[next_x][next_y] == 0)
            {
                q.push(make_p(next_x, next_y));
                visited[next_x][next_y] = true;
            }
        }
    }
}

void build_wall(int idx)
{
    if (idx == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            myMap[space[path[i]].x][space[path[i]].y] = 1;
        }
        memset(visited, 0, sizeof(visited));

        bfs();

        int safe_zone = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!visited[i][j] && myMap[i][j] == 0)
                    safe_zone += 1;
            }
        }

        if (safe_zone > answer)
            answer = safe_zone;

        for (int i = 0; i < 3; i++)
        {
            myMap[space[path[i]].x][space[path[i]].y] = 0;
        }
    }
    else
    {
        for (int i = 0; i < space.size(); i++)
        {
            if (idx == 0 || path[idx - 1] < i)
            {
                path[idx] = i;
                build_wall(idx + 1);
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = x;

            if (x == 0)
                space.push_back(make_p(i, j));

            if (x == 2)
                virus.push_back(make_p(i, j));
        }
    }

    answer = -1;

    build_wall(0);

    cout << answer << endl;
}