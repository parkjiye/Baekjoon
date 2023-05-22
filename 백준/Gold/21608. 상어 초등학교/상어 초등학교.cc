#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct chair
{
    int x;
    int y;
    int favor = 0;
    int blank = 0;

    chair(int x, int y, int favor, int blank) : x(x), y(y), favor(favor), blank(blank) {}
    chair() {}
};

struct seat
{
    bool occupied = false;
    int idx = 0;

    seat(int occupied, int idx) : occupied(occupied), idx(idx) {}
    seat() {}
};

seat myMap[25][25];

bool compare(chair a, chair b)
{
    if (a.favor == b.favor)
    {
        if (a.blank == b.blank)
        {
            if (a.x == b.x)
            {
                return a.y < b.y;
            }
            return a.x < b.x;
        }
        return a.blank > b.blank;
    }
    return a.favor > b.favor;
}

int friends[500][4];
queue<int> q;

int main()
{
    FASTIO();
    cin >> N;

    int students = N * N;

    for (int i = 0; i < students; i++)
    {
        int index;
        cin >> index;
        q.push(index);

        for (int j = 0; j < 4; j++)
        {
            int x;
            cin >> x;
            friends[index][j] = x;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        vector<chair> s;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!myMap[i][j].occupied)
                {
                    chair temp = chair(i, j, 0, 0);

                    for (int k = 0; k < 4; k++)
                    {
                        int next_x = i + dx[k];
                        int next_y = j + dy[k];

                        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N)
                        {

                            if (!myMap[next_x][next_y].occupied)
                            {
                                temp.blank += 1;
                            }
                            else
                            {
                                for (int p = 0; p < 4; p++)
                                {
                                    if (myMap[next_x][next_y].idx == friends[cur][p])
                                    {
                                        temp.favor += 1;
                                    }
                                }
                            }
                        }
                    }

                    s.push_back(temp);
                }
            }
        }

        sort(s.begin(), s.end(), compare);

        chair cur_seat = s[0];

        myMap[cur_seat.x][cur_seat.y].idx = cur;
        myMap[cur_seat.x][cur_seat.y].occupied = true;
    }
    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int cur = myMap[i][j].idx;
            int cnt = 0;

            for (int k = 0; k < 4; k++)
            {
                int next_x = i + dx[k];
                int next_y = j + dy[k];

                if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N)
                {
                    for (int p = 0; p < 4; p++)
                    {
                        if (myMap[next_x][next_y].idx == friends[cur][p])
                        {
                            cnt += 1;
                        }
                    }
                }
            }

            if (cnt == 1)
            {
                answer += 1;
            }
            else if (cnt == 2)
            {
                answer += 10;
            }
            else if (cnt == 3)
            {
                answer += 100;
            }
            else if (cnt == 4)
            {
                answer += 1000;
            }
        }
    }

    cout << answer << endl;
}