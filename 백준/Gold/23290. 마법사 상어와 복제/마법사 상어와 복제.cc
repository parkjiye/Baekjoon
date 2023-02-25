#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int M, S;

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int sx[4] = {-1, 0, 1, 0};
int sy[4] = {0, -1, 0, 1};

struct p
{
    int x;
    int y;
    int d;
};

vector<p> fish[4][4];
vector<p> copyMap[4][4];

int smells[4][4];
int total = 0;

p shark;
int max_fish;
vector<p> max_route(3);

bool visited[4][4];

p make_p(int x, int y, int d)
{
    p temp;
    temp.x = x;
    temp.y = y;
    temp.d = d;

    return temp;
}

void duplicate()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            copyMap[i][j] = fish[i][j];
        }
    }
}

void move()
{
    vector<p> temp[4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int f = 0; f < fish[i][j].size(); f++)
            {
                p cur_fish = fish[i][j][f];
                bool move = false;

                for (int k = 8; k > 0; k--)
                {
                    int next_x = cur_fish.x + dx[(cur_fish.d + k) % 8];
                    int next_y = cur_fish.y + dy[(cur_fish.d + k) % 8];

                    if (next_x >= 0 && next_x < 4 && next_y >= 0 && next_y < 4)
                    {
                        if ((next_x != shark.x || next_y != shark.y) && smells[next_x][next_y] == 0)
                        {
                            temp[next_x][next_y].push_back(make_p(next_x, next_y, (cur_fish.d + k) % 8));
                            move = true;
                            break;
                        }
                    }
                }

                if (!move)
                {
                    temp[cur_fish.x][cur_fish.y].push_back(make_p(cur_fish.x, cur_fish.y, cur_fish.d));
                }
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            fish[i][j] = temp[i][j];
        }
    }
}

void move_shark(p sh, int time, vector<p> route)
{
    if (time == 3)
    {
        if (sh.d > max_fish)
        {
            for (int i = 0; i < 3; i++)
            {
                max_route[i] = make_p(route[i].x, route[i].y, 0);
                max_fish = sh.d;
            }
            return;
        }
        else
        {
            return;
        }
    }
    else
    {
        for (int k = 0; k < 4; k++)
        {
            int next_x = sh.x + sx[k];
            int next_y = sh.y + sy[k];

            if (next_x >= 0 && next_x < 4 && next_y >= 0 && next_y < 4)
            {
                if (!visited[next_x][next_y])
                {
                    route[time] = make_p(next_x, next_y, 0);
                    visited[next_x][next_y] = true;
                    move_shark(make_p(next_x, next_y, sh.d + fish[next_x][next_y].size()), time + 1, route);
                    visited[next_x][next_y] = false;
                }
                else
                {
                    route[time] = make_p(next_x, next_y, 0);
                    move_shark(make_p(next_x, next_y, sh.d), time + 1, route);
                }
            }
        }
    }
}

int main()
{
    int x, y, d;
    cin >> M >> S;

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> d;
        fish[x - 1][y - 1].push_back(make_p(x - 1, y - 1, d - 1));
    }

    cin >> x >> y;
    shark = make_p(x - 1, y - 1, 0);

    for (int t = 1; t <= S; t++)
    {
        // 복제 마법 실시

        duplicate();

        // 물고기가 한 칸 이동

        move();

        // 상어가 연속해서 3칸 이동

        max_fish = -1;
        vector<p> r(3);
        memset(visited, 0, sizeof(visited));
        // visited[shark.x][shark.y] = true;
        move_shark(shark, 0, r);

        vector<p> temp[4][4];

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                temp[i][j] = fish[i][j];
            }
        }

        for (int k = 0; k < 3; k++)
        {
            p cur = max_route[k];

            if (temp[cur.x][cur.y].size() > 0)
            {
                smells[cur.x][cur.y] = t;
                temp[cur.x][cur.y].clear();
            }
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                fish[i][j] = temp[i][j];
            }
        }
        shark = make_p(max_route[2].x, max_route[2].y, 0);

        // 두 번 전 연습에서 생긴 물고기의 냄새 사라짐

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (smells[i][j] == 0)
                    continue;
                if (t - smells[i][j] == 2)
                    smells[i][j] = 0;
            }
        }

        // 복제 마법 완료

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < copyMap[i][j].size(); k++)
                {
                    fish[i][j].push_back(copyMap[i][j][k]);
                }
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            total += fish[i][j].size();
        }
    }
    cout << total << endl;
}