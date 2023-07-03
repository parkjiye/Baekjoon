#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct enemy
{
    int x;
    int y;
    int dist;
    bool killed;

    enemy(int x, int y, int dist, bool killed) : x(x), y(y), dist(dist), killed(killed) {}
    enemy() {}
};

bool compare(enemy a, enemy b)
{
    if (a.dist == b.dist)
    {
        return a.y < b.y;
    }

    return a.dist < b.dist;
}

struct archer
{
    int x;
    int y;

    archer(int x, int y) : x(x), y(y) {}
    archer() {}
};

int N, M, D;
int answer;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int myMap[18][18];
bool visited[18][18];

// vector<enemy> e;

int path[18];

int kill_enemy()
{
    vector<archer> a;

    int killed_enemy = 0;

    for (int i = 0; i < 3; i++)
    {
        a.push_back(archer(N, path[i]));
    }

    // 적을 쏘기 시작
    int temp[18][18];
    memcpy(temp, myMap, sizeof(myMap));

    while (1)
    {
        vector<enemy> e;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (temp[i][j] == 1)
                {
                    e.push_back(enemy(i, j, 0, false));
                }
            }
        }

        if (e.size() == 0)
        {
            return killed_enemy;
        }

        for (int i = 0; i < 3; i++)
        {
            archer cur_arch = a[i];

            for (int j = 0; j < e.size(); j++)
            {
                enemy cur_enemy = e[j];

                int dist = abs(cur_arch.x - cur_enemy.x) + abs(cur_arch.y - cur_enemy.y);
                e[j].dist = dist;
            }

            sort(e.begin(), e.end(), compare);

            for (int j = 0; j < e.size(); j++)
            {
                if (e[j].dist <= D)
                {
                    e[j].killed = true;
                    break;
                }
            }
        }

        for (int i = 0; i < e.size(); i++)
        {
            if (e[i].killed)
            {
                temp[e[i].x][e[i].y] = 0;
                killed_enemy += 1;
                continue;
            }
            else
            {
                int next_x = e[i].x + 1;
                int next_y = e[i].y;

                if (next_x == N)
                {
                    temp[e[i].x][e[i].y] = 0;
                }
                else
                {
                    temp[e[i].x][e[i].y] = 0;
                    e[i].x = next_x;
                    temp[e[i].x][e[i].y] = 1;
                }
            }
        }
    }
}

void set_archer(int idx)
{
    if (idx == 3)
    {
        int cnt = kill_enemy();

        if (cnt > answer)
        {
            answer = cnt;
        }
    }

    else
    {
        for (int i = 0; i < M; i++)
        {
            if (idx == 0 || path[idx - 1] < i)
            {
                path[idx] = i;
                set_archer(idx + 1);
            }
        }
    }
}

int main()
{
    FASTIO();
    cin >> N >> M >> D;

    answer = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = x;
        }
    }

    // 궁수 3명 배치
    set_archer(0);

    cout << answer << endl;
}