#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct shark
{
    int speed;
    int dir;
    int size;

    shark(int speed, int dir, int size) : speed(speed), dir(dir), size(size) {}
    shark() {}
};

struct water
{
    vector<shark> s;

    water() {}
};

bool compare(shark a, shark b)
{
    return a.size > b.size;
}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int R, C, M;

water myMap[105][105];

int main()
{
    FASTIO();
    cin >> R >> C >> M;

    for (int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;

        myMap[r - 1][c - 1].s.push_back(shark(s, d - 1, z));
    }

    int pos = 0;
    int ans = 0;

    while (pos < C)
    {
        for (int i = 0; i < R; i++)
        {
            if (myMap[i][pos].s.size() > 0)
            {
                ans += myMap[i][pos].s[0].size;
                myMap[i][pos].s.clear();
                break;
            }
        }

        pos += 1;

        // 상어 이동
        water temp[105][105];

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                temp[i][j].s = myMap[i][j].s;
            }
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (myMap[i][j].s.size() > 0)
                {
                    shark cur = myMap[i][j].s[0];

                    temp[i][j].s.erase(temp[i][j].s.begin());

                    int moving;

                    if (cur.dir < 2)
                    {
                        int cur_x = i;
                        moving = cur.speed % ((R - 1) * 2);

                        for (int k = 0; k < moving; k++)
                        {
                            int next_x = cur_x + dx[cur.dir];

                            if (next_x < 0 || next_x >= R)
                            {
                                if (cur.dir == 0)
                                {
                                    cur.dir = 1;
                                }
                                else
                                {
                                    cur.dir = 0;
                                }

                                next_x = cur_x + dx[cur.dir];
                            }

                            cur_x = next_x;
                        }

                        temp[cur_x][j].s.push_back(cur);
                    }
                    else
                    {
                        int cur_y = j;
                        moving = cur.speed % ((C - 1) * 2);

                        for (int k = 0; k < moving; k++)
                        {

                            int next_y = cur_y + dy[cur.dir];

                            if (next_y < 0 || next_y >= C)
                            {
                                if (cur.dir == 2)
                                {
                                    cur.dir = 3;
                                }
                                else
                                {
                                    cur.dir = 2;
                                }

                                next_y = cur_y + dy[cur.dir];
                            }

                            cur_y = next_y;
                        }

                        temp[i][cur_y].s.push_back(cur);
                    }
                }
            }
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                myMap[i][j].s = temp[i][j].s;

                if (myMap[i][j].s.size() > 1)
                {
                    vector<shark> v = myMap[i][j].s;

                    sort(v.begin(), v.end(), compare);

                    myMap[i][j].s.clear();
                    myMap[i][j].s.push_back(v[0]);
                }
            }
        }
    }

    cout << ans << endl;
}