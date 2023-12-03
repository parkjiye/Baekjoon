#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct bamboo
{
    int x;
    int y;
    int b;

    bamboo(int x, int y, int b) : x(x), y(y), b(b) {}
    bamboo() {}

    bool operator<(const bamboo temp) const
    {
        return b < temp.b;
    }
};

int N;
int myMap[505][505];
int forest[505][505];

priority_queue<bamboo> pq;

void bfs()
{

    while (!pq.empty())
    {
        bamboo cur = pq.top();
        pq.pop();

        int temp = 0;

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N)
            {
                if (myMap[next_x][next_y] > temp && forest[next_x][next_y] > cur.b)
                {
                    temp = myMap[next_x][next_y];
                }
            }
        }

        myMap[cur.x][cur.y] = temp + 1;
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

            pq.push(bamboo(i, j, x));
            forest[i][j] = x;
        }
    }

    bfs();
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (myMap[i][j] > ans)
            {
                ans = myMap[i][j];
            }
        }
    }

    cout << ans << "\n";
}