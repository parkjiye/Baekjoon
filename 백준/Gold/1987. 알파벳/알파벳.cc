#include <iostream>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int R, C;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char myMap[23][23];
int check[26];
bool visited[23][23];

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y) {}
    p() {}
};

int answer;

void backtracking(p pos, int cnt)
{
    // cout << pos.x << " " << pos.y << " " << cnt << endl;
    if (cnt > answer)
        answer = cnt;

    for (int k = 0; k < 4; k++)
    {
        int next_x = pos.x + dx[k];
        int next_y = pos.y + dy[k];

        if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C)
        {
            if (check[myMap[next_x][next_y] - 'A'] == 0)
            {
                check[myMap[next_x][next_y] - 'A'] = 1;
                backtracking(p(next_x, next_y), cnt + 1);
                check[myMap[next_x][next_y] - 'A'] = 0;
            }
        }
    }
}

int main()
{
    FASTIO();

    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char x;
            cin >> x;

            myMap[i][j] = x;
        }
    }

    answer = 1;

    check[myMap[0][0] - 'A'] = 1;

    backtracking(p(0, 0), 1);

    cout << answer << endl;
}