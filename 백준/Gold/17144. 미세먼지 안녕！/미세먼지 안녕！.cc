#include <iostream>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int R, C, T;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bx[4] = {0, -1, 0, 1};
int by[4] = {1, 0, -1, 0};

int cx[4] = {0, 1, 0, -1};
int cy[4] = {1, 0, -1, 0};

struct room
{
    int sand;
    bool cleaner;

    room() {}
    room(int sand, bool cleaner) : sand(sand), cleaner(cleaner) {} /* data */
};

room myMap[55][55];

struct cleaner
{
    int x;
    int y;

    cleaner() {}
    cleaner(int x, int y) : x(x), y(y) {}
};

cleaner upper_cleaner;
cleaner bottom_cleaner;

void move_sand()
{
    room temp[55][55];

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            temp[i][j].sand = 0;
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (!myMap[i][j].cleaner)
            {
                for (int k = 0; k < 4; k++)
                {
                    int next_x = i + dx[k];
                    int next_y = j + dy[k];

                    if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C && !myMap[next_x][next_y].cleaner)
                    {
                        temp[next_x][next_y].sand += myMap[i][j].sand / 5;
                        temp[i][j].sand -= myMap[i][j].sand / 5;
                    }
                }
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            myMap[i][j].sand += temp[i][j].sand;
        }
    }
}

void bottom_clean()
{
    room temp[55][55];
    memcpy(temp, myMap, sizeof(myMap));

    int cur_x = bottom_cleaner.x;
    int cur_y = bottom_cleaner.y;

    int total = C * 2 + 2 * (R - cur_x - 2) - 1;

    int k = 0;

    while (total--)
    {
        int next_x = cur_x + cx[k % 4];
        int next_y = cur_y + cy[k % 4];

        if (next_x >= bottom_cleaner.x && next_y >= 0 && next_x < R && next_y < C)
        {
            temp[next_x][next_y].sand = myMap[cur_x][cur_y].sand;
        }
        else
        {
            k += 1;
            next_x = cur_x + cx[k % 4];
            next_y = cur_y + cy[k % 4];

            temp[next_x][next_y].sand = myMap[cur_x][cur_y].sand;
        }

        cur_x = next_x;
        cur_y = next_y;
    }

    temp[bottom_cleaner.x][bottom_cleaner.y].sand = 0;

    for (int i = bottom_cleaner.x; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            myMap[i][j].sand = temp[i][j].sand;
        }
    }
}

void upper_clean()
{
    room temp[55][55];
    memcpy(temp, myMap, sizeof(myMap));

    int cur_x = upper_cleaner.x;
    int cur_y = upper_cleaner.y;

    int total = C * 2 + 2 * (cur_x - 1) - 1;

    int k = 0;

    while (total--)
    {
        int next_x = cur_x + bx[k % 4];
        int next_y = cur_y + by[k % 4];

        if (next_x >= 0 && next_y >= 0 && next_x < upper_cleaner.x + 1 && next_y < C)
        {
            temp[next_x][next_y].sand = myMap[cur_x][cur_y].sand;
        }
        else
        {
            k += 1;
            next_x = cur_x + bx[k % 4];
            next_y = cur_y + by[k % 4];

            temp[next_x][next_y].sand = myMap[cur_x][cur_y].sand;
        }

        cur_x = next_x;
        cur_y = next_y;
    }

    temp[upper_cleaner.x][upper_cleaner.y].sand = 0;

    for (int i = 0; i <= upper_cleaner.x; i++)
    {
        for (int j = 0; j < C; j++)
        {
            myMap[i][j].sand = temp[i][j].sand;
        }
    }
}

int main()
{
    FASTIO();

    cin >> R >> C >> T;
    int cnt = 0;
    int answer = 0;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int x;
            cin >> x;

            if (x == -1)
            {
                if (cnt == 0)
                {
                    upper_cleaner = cleaner(i, j);
                    cnt += 1;
                }
                else
                {
                    bottom_cleaner = cleaner(i, j);
                }
                myMap[i][j] = room(0, true);
            }
            else
            {
                myMap[i][j] = room(x, false);
            }
        }
    }

    for (int t = 0; t < T; t++)
    {
        // 확산
        move_sand();
        // 공기청정기

        upper_clean();
        bottom_clean();
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            answer += myMap[i][j].sand;
        }
    }

    cout << answer << endl;

    return 0;
}