#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct Fish
{
    bool eaten;
    int x;
    int y;
    int d;
};

Fish make_fish(bool eaten, int x, int y, int d)
{
    Fish temp;
    temp.eaten = eaten;
    temp.x = x;
    temp.y = y;
    temp.d = d;
    return temp;
}

int myMap[4][4];
Fish fish[18];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int answer;

void move_fish()
{
    for (int i = 1; i <= 16; i++)
    {
        if (!fish[i].eaten)
        {
            Fish cur = fish[i];
            bool move = false;

            for (int k = 0; k < 8; k++)
            {
                if (move)
                    break;
                int next_x = cur.x + dx[(cur.d + k) % 8];
                int next_y = cur.y + dy[(cur.d + k) % 8];

                if (next_x >= 0 && next_x < 4 && next_y >= 0 && next_y < 4 && myMap[next_x][next_y] != -1)
                {
                    if (myMap[next_x][next_y])
                    {
                        int next_idx = myMap[next_x][next_y];

                        Fish temp = fish[i];
                        fish[i] = make_fish(false, next_x, next_y, (cur.d + k) % 8);
                        fish[next_idx] = make_fish(false, cur.x, cur.y, fish[next_idx].d);

                        int temp_id = myMap[cur.x][cur.y];
                        myMap[cur.x][cur.y] = next_idx;
                        myMap[next_x][next_y] = temp_id;
                    }
                    else
                    {
                        fish[i] = make_fish(false, next_x, next_y, (cur.d + k) % 8);
                        myMap[cur.x][cur.y] = 0;
                        myMap[next_x][next_y] = i;
                    }

                    move = true;
                }
            }
        }
    }
}

void backtracking(int x, int y, int d, int idx)
{
    if (answer < idx)
    {
        answer = idx;
    }

    int myMap_cpy[4][4];
    Fish fish_cpy[18];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            myMap_cpy[i][j] = myMap[i][j];
        }
    }

    for (int i = 1; i <= 16; i++)
    {
        fish_cpy[i] = fish[i];
    }

    move_fish();

    for (int i = 1; i <= 3; i++)
    {
        int next_x = x + dx[d] * i;
        int next_y = y + dy[d] * i;

        if (next_x >= 0 && next_x < 4 && next_y >= 0 && next_y < 4)
        {
            if (myMap[next_x][next_y] == 0)
            {
                continue;
            }
            int f_idx = myMap[next_x][next_y];
            int n_d = fish[f_idx].d;

            fish[f_idx].eaten = true;
            myMap[x][y] = 0;
            myMap[next_x][next_y] = -1;

            backtracking(next_x, next_y, n_d, idx + f_idx);

            fish[f_idx].eaten = false;
            myMap[x][y] = -1;
            myMap[next_x][next_y] = f_idx;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            myMap[i][j] = myMap_cpy[i][j];
        }
    }

    for (int i = 1; i <= 16; i++)
    {
        fish[i] = fish_cpy[i];
    }
}

int main()
{
    FASTIO();

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int x, y;
            cin >> x >> y;

            myMap[i][j] = x;
            fish[x] = make_fish(false, i, j, y - 1);
        }
    }

    int first_fish = myMap[0][0];
    int f_d = fish[first_fish].d;
    fish[first_fish].eaten = true;
    myMap[0][0] = -1;

    backtracking(0, 0, f_d, first_fish);

    cout << answer << endl;

    return 0;
}