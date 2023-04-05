#include <iostream>
#include <queue>
#include <string.h>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M, K;

int d[6] = {1, 6, 3, 4, 2, 5};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void move_dice(int dir)
{
    // 동
    if (dir == 0)
    {
        int temp1 = d[0];
        d[0] = d[3];
        d[3] = temp1;

        int temp2 = d[1];
        d[1] = d[2];
        d[2] = temp2;

        int temp3 = d[2];
        d[2] = d[3];
        d[3] = temp3;
    }

    // 서
    if (dir == 2)
    {
        int temp1 = d[0];
        d[0] = d[2];
        d[2] = temp1;

        int temp2 = d[1];
        d[1] = d[3];
        d[3] = temp2;

        int temp3 = d[2];
        d[2] = d[3];
        d[3] = temp3;
    }

    // 북
    if (dir == 3)
    {
        int temp1 = d[0];
        d[0] = d[5];
        d[5] = temp1;

        int temp2 = d[1];
        d[1] = d[4];
        d[4] = temp2;

        int temp3 = d[4];
        d[4] = d[5];
        d[5] = temp3;
    }

    // 남

    if (dir == 1)
    {
        int temp1 = d[0];
        d[0] = d[4];
        d[4] = temp1;

        int temp2 = d[1];
        d[1] = d[5];
        d[5] = temp2;

        int temp3 = d[4];
        d[4] = d[5];
        d[5] = temp3;
    }
}

int myMap[21][21];

struct dice
{
    int x;
    int y;
};

dice make_dice(int x, int y)
{
    dice temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

bool visited[22][22];

int bfs(dice d, int num)
{
    queue<dice> q;
    q.push(d);
    visited[d.x][d.y] = true;
    int cnt = 1;

    while (!q.empty())
    {
        dice cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && !visited[next_x][next_y] && myMap[next_x][next_y] == num)
            {
                q.push(make_dice(next_x, next_y));
                visited[next_x][next_y] = true;
                cnt += 1;
            }
        }
    }

    return cnt;
}

int main()
{
    FASTIO();

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;
            myMap[i][j] = x;
        }
    }

    dice mydice = make_dice(0, 0);

    // 동 남 서 북
    int dir = 0;
    int answer = 0;

    for (int k = 0; k < K; k++)
    {
        int next_x = mydice.x + dx[dir];
        int next_y = mydice.y + dy[dir];

        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
        {
            move_dice(dir);
        }
        else
        {
            dir = (dir + 2) % 4;
            move_dice(dir);

            next_x = mydice.x + dx[dir];
            next_y = mydice.y + dy[dir];
        }

        int cur = myMap[next_x][next_y];
        int cur_d = d[1];

        if (cur_d > cur)
        {
            dir = (dir + 1) % 4;
        }
        else if (cur_d < cur)
        {
            dir = (dir - 1 + 4) % 4;
        }

        mydice = make_dice(next_x, next_y);

        // cout << dir << endl;

        memset(visited, 0, sizeof(visited));

        answer += bfs(mydice, cur) * cur;
    }

    cout << answer << endl;
}