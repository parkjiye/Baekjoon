#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

int myMap[17][17];
bool visited[17][17];

int answer;

struct pipe
{
    int x;
    int y;
    int type;

    pipe() {}
    pipe(int x, int y, int type) : x(x), y(y), type(type) {}
};

void bfs(pipe p)
{
    int next_x;
    int next_y;
    if (p.x == N - 1 && p.y == N - 1)
    {
        answer += 1;
        return;
    }
    // 가로
    if (p.type == 0)
    {
        // 가로
        next_x = p.x;
        next_y = p.y + 1;

        if (next_y < N && !visited[next_x][next_y] && myMap[next_x][next_y] != 1)
        {
            visited[next_x][next_y] = true;
            bfs(pipe(next_x, next_y, 0));
            visited[next_x][next_y] = false;
        }

        // 대각선
        next_x = p.x + 1;
        next_y = p.y + 1;

        if (next_x < N && next_y < N && !visited[next_x][next_y] && !visited[next_x - 1][next_y] && !visited[next_x][next_y - 1] && myMap[next_x][next_y] != 1 && myMap[next_x - 1][next_y] != 1 && myMap[next_x][next_y - 1] != 1)
        {
            visited[next_x][next_y] = true;
            visited[next_x - 1][next_y] = true;
            visited[next_x][next_y - 1] = true;
            bfs(pipe(next_x, next_y, 1));
            visited[next_x][next_y] = false;
            visited[next_x - 1][next_y] = false;
            visited[next_x][next_y - 1] = false;
        }
    }
    // 대각선
    else if (p.type == 1)
    {
        // 가로
        next_x = p.x;
        next_y = p.y + 1;

        if (next_y < N && !visited[next_x][next_y] && myMap[next_x][next_y] != 1)
        {
            visited[next_x][next_y] = true;
            bfs(pipe(next_x, next_y, 0));
            visited[next_x][next_y] = false;
        }

        // 세로
        next_x = p.x + 1;
        next_y = p.y;

        if (next_x < N && !visited[next_x][next_y] && myMap[next_x][next_y] != 1)
        {
            visited[next_x][next_y] = true;
            bfs(pipe(next_x, next_y, 2));
            visited[next_x][next_y] = false;
        }

        // 대각선
        next_x = p.x + 1;
        next_y = p.y + 1;

        if (next_x < N && next_y < N && !visited[next_x][next_y] && !visited[next_x - 1][next_y] && !visited[next_x][next_y - 1] && myMap[next_x][next_y] != 1 && myMap[next_x - 1][next_y] != 1 && myMap[next_x][next_y - 1] != 1)
        {
            visited[next_x][next_y] = true;
            visited[next_x - 1][next_y] = true;
            visited[next_x][next_y - 1] = true;
            bfs(pipe(next_x, next_y, 1));
            visited[next_x][next_y] = false;
            visited[next_x - 1][next_y] = false;
            visited[next_x][next_y - 1] = false;
        }
    }
    // 세로
    else
    {
        // 세로
        next_x = p.x + 1;
        next_y = p.y;

        if (next_x < N && !visited[next_x][next_y] && myMap[next_x][next_y] != 1)
        {
            visited[next_x][next_y] = true;
            bfs(pipe(next_x, next_y, 2));
            visited[next_x][next_y] = false;
        }

        // 대각선
        next_x = p.x + 1;
        next_y = p.y + 1;

        if (next_x < N && next_y < N && !visited[next_x][next_y] && !visited[next_x - 1][next_y] && !visited[next_x][next_y - 1] && myMap[next_x][next_y] != 1 && myMap[next_x - 1][next_y] != 1 && myMap[next_x][next_y - 1] != 1)
        {
            visited[next_x][next_y] = true;
            visited[next_x - 1][next_y] = true;
            visited[next_x][next_y - 1] = true;
            bfs(pipe(next_x, next_y, 1));
            visited[next_x][next_y] = false;
            visited[next_x - 1][next_y] = false;
            visited[next_x][next_y - 1] = false;
        }
    }
}

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = x;
        }
    }
    answer = 0;
    visited[0][0] = true;
    visited[0][1] = true;

    bfs(pipe(0, 1, 0));

    cout << answer << endl;
    return 0;
}
