#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y) {}
    p() {}
};

struct maze
{
    p minsik;
    int tr;
    int key;

    maze() {}
    maze(p minsik, int tr, int key) : minsik(minsik), tr(tr), key(key) {}
};

// 삽입
// 10101 | 1<<3
int N, M;
bool visited[55][55][1 << 6];
char myMap[55][55];
queue<maze> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs()
{
    while (!q.empty())
    {
        maze cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.minsik.x + dx[k];
            int next_y = cur.minsik.y + dy[k];

            if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && myMap[next_x][next_y] != '#' && !visited[next_x][next_y][cur.key])
            {
                // 1일 경우
                if (myMap[next_x][next_y] == '1')
                {
                    return cur.tr + 1;
                }
                // 문일 경우
                else if (myMap[next_x][next_y] >= 'A' && myMap[next_x][next_y] <= 'F')
                {
                    if (cur.key & 1 << (myMap[next_x][next_y] - 'A'))
                    {
                        visited[next_x][next_y][cur.key] = true;
                        q.push(maze(p(next_x, next_y), cur.tr + 1, cur.key));
                    }
                }
                // 열쇄일 경우
                else if (myMap[next_x][next_y] >= 'a')
                {
                    q.push(maze(p(next_x, next_y), cur.tr + 1, cur.key | 1 << (myMap[next_x][next_y] - 'a')));
                    visited[next_x][next_y][cur.key | 1 << (myMap[next_x][next_y] - 'a')] = true;
                }
                // 빈 칸인 경우
                else
                {
                    q.push(maze(p(next_x, next_y), cur.tr + 1, cur.key));
                    visited[next_x][next_y][cur.key] = true;
                }
            }
        }
    }

    return -1;
}

int main()
{
    FASTIO();
    cin >> N >> M;

    p start;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++)
        {
            myMap[i][j] = s[j];

            if (s[j] == '0')
            {
                start = p(i, j);
            }
        }
    }

    visited[start.x][start.y][0] = true;
    q.push(maze(start, 0, 0));

    cout << bfs() << "\n";
}
