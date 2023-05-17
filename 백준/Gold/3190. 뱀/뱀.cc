#include <iostream>
#include <deque>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, K, L;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct space
{
    bool snake = false;
    bool apple = false;

    space(bool snake, bool apple) : snake(snake), apple(apple) {}
    space() {}
};

struct body
{
    int x;
    int y;

    body(int x, int y) : x(x), y(y) {}
    body() {}
};

space myMap[105][105];

deque<body> snake;
queue<pair<int, char>> cmd;

int main()
{
    FASTIO();

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            myMap[i][j].snake = false;
            myMap[i][j].apple = false;
        }
    }

    for (int k = 0; k < K; k++)
    {
        int x, y;
        cin >> x >> y;

        myMap[x - 1][y - 1].apple = true;
    }

    cin >> L;

    int d = 0;
    int length = 1;

    snake.push_front(body(0, 0));
    myMap[0][0].snake = true;

    int t = 0;

    for (int i = 0; i < L; i++)
    {
        int cnt;
        char dir;

        cin >> cnt >> dir;

        cmd.push({cnt, dir});
    }

    while (1)
    {
        if (t == cmd.front().first)
        {
            if (cmd.front().second == 'D')
            {
                d = (d + 1) % 4;
            }
            else
            {
                d = (d - 1 + 4) % 4;
            }

            cmd.pop();
        }

        t += 1;

        int next_x = snake.front().x + dx[d];
        int next_y = snake.front().y + dy[d];

        if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < N && !myMap[next_x][next_y].snake)
        {
            snake.push_front(body(next_x, next_y));
            myMap[next_x][next_y].snake = true;
            length += 1;

            if (myMap[next_x][next_y].apple)
            {
                myMap[next_x][next_y].apple = false;
            }
            else
            {
                myMap[snake.back().x][snake.back().y].snake = false;
                snake.pop_back();
                length -= 1;
            }
        }
        else
        {
            break;
        }
    }

    cout << t << endl;
    return 0;
}