#include <iostream>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, K;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

struct horse
{
    int x;
    int y;
    int dir;

    horse(int x, int y, int dir) : x(x), y(y), dir(dir) {}
    horse() {}
};

struct board
{
    deque<int> dq;
    int color;

    board() {}
};

board myMap[15][15];
horse horses[15];

bool check()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (myMap[i][j].dq.size() >= 4)
            {
                return false;
            }
        }
    }

    return true;
}

void move_white(int cur_x, int cur_y, int next_x, int next_y, int k)
{
    deque<int> tmp;

    while (myMap[cur_x][cur_y].dq.size())
    {
        if (myMap[cur_x][cur_y].dq.front() == k)
        {
            tmp.push_back(k);
            myMap[cur_x][cur_y].dq.pop_front();

            while (tmp.size())
            {
                int c = tmp.back();
                // cout << c << "\n";
                tmp.pop_back();

                myMap[next_x][next_y].dq.push_front(c);
                horses[c].x = next_x;
                horses[c].y = next_y;
            }

            return;
        }
        else
        {
            tmp.push_back(myMap[cur_x][cur_y].dq.front());
            myMap[cur_x][cur_y].dq.pop_front();
        }
    }
}

void move_red(int cur_x, int cur_y, int next_x, int next_y, int k)
{
    deque<int> tmp;

    while (myMap[cur_x][cur_y].dq.size())
    {
        if (myMap[cur_x][cur_y].dq.front() == k)
        {
            tmp.push_back(k);
            myMap[cur_x][cur_y].dq.pop_front();

            while (tmp.size())
            {
                int c = tmp.front();
                // cout << c << "\n";
                tmp.pop_front();

                myMap[next_x][next_y].dq.push_front(c);
                horses[c].x = next_x;
                horses[c].y = next_y;
            }

            return;
        }
        else
        {
            tmp.push_back(myMap[cur_x][cur_y].dq.front());
            myMap[cur_x][cur_y].dq.pop_front();
        }
    }
}

void print()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << myMap[i][j].dq.size() << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    FASTIO();
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;

            myMap[i][j].color = x;
        }
    }

    for (int i = 1; i <= K; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;

        myMap[x - 1][y - 1].dq.push_front(i);
        horses[i] = horse(x - 1, y - 1, d - 1);
    }

    int trn = 0;

    while (check())
    {
        if (trn >= 1000)
        {
            cout << -1 << "\n";
            return 0;
        }

        // print();

        for (int k = 1; k <= K; k++)
        {
            if (!check())
            {
                cout << trn + 1 << "\n";
                return 0;
            }

            horse cur = horses[k];

            int next_x = cur.x + dx[cur.dir];
            int next_y = cur.y + dy[cur.dir];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N || myMap[next_x][next_y].color == 2)
            {
                if (cur.dir == 0 || cur.dir == 2)
                {
                    cur.dir += 1;
                }
                else
                {
                    cur.dir -= 1;
                }

                next_x = cur.x + dx[cur.dir];
                next_y = cur.y + dy[cur.dir];

                horses[k].dir = cur.dir;

                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N || myMap[next_x][next_y].color == 2)
                {
                    continue;
                }
                else
                {
                    if (myMap[next_x][next_y].color == 1)
                    {
                        move_red(cur.x, cur.y, next_x, next_y, k);
                    }
                    else
                    {
                        move_white(cur.x, cur.y, next_x, next_y, k);
                    }
                }
            }
            else if (myMap[next_x][next_y].color == 1)
            {
                move_red(cur.x, cur.y, next_x, next_y, k);
            }
            else
            {
                move_white(cur.x, cur.y, next_x, next_y, k);
            }

            // print();
        }

        trn += 1;
    }
    cout << trn << "\n";
}