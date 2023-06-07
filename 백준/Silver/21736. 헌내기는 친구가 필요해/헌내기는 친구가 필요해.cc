#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
char myMap[605][605];
bool visited[605][605];

int answer;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y) {}
    p() {}
};

void bfs(p start)
{
    queue<p> q;
    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && !visited[next_x][next_y] && myMap[next_x][next_y] != 'X')
            {
                visited[next_x][next_y] = true;
                q.push(p(next_x, next_y));
            }
        }
    }
}

int main()
{
    FASTIO();
    cin >> N >> M;

    p start;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char x;
            cin >> x;
            myMap[i][j] = x;

            if (x == 'I')
            {
                start = p(i, j);
            }
        }
    }

    bfs(start);
    answer = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (myMap[i][j] == 'P' && visited[i][j])
            {
                answer += 1;
            }
        }
    }

    if (answer)
    {
        cout << answer << endl;
    }
    else
    {
        cout << "TT" << endl;
    }

    return 0;
}