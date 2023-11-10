#include <iostream>
#include <queue>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M, T;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct p
{
    int x;
    int y;

    p() {}
    p(int x, int y) : x(x), y(y) {}
};

deque<int> dq[52];
bool visited[52][52];

int bfs(p start, int num)
{
    queue<p> q;
    q.push(start);
    visited[start.x][start.y] = true;

    bool find = false;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = (cur.y + dy[k] + M) % M;

            if (next_x >= 1 && next_x <= N && !visited[next_x][next_y] && dq[next_x].at(next_y) == num)
            {
                find = true;
                q.push(p(next_x, next_y));
                visited[next_x][next_y] = true;
                dq[next_x].at(next_y) = 0;
            }
        }
    }

    if (find)
    {
        dq[start.x].at(start.y) = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    FASTIO();
    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;

            dq[i].push_back(x);
        }
    }

    for (int t = 0; t < T; t++)
    {
        int x, d, k;
        cin >> x >> d >> k;

        for (int i = x; i <= N; i += x)
        {
            for (int j = 0; j < k; j++)
            {
                if (d == 1)
                {
                    int temp = dq[i].front();
                    dq[i].pop_front();
                    dq[i].push_back(temp);
                }
                else
                {
                    int temp = dq[i].back();
                    dq[i].pop_back();
                    dq[i].push_front(temp);
                }
            }
        }

        memset(visited, 0, sizeof(visited));

        int check = 0;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!visited[i][j] && dq[i].at(j) != 0)
                {
                    check += bfs(p(i, j), dq[i].at(j));
                }
            }
        }

        if (check == 0)
        {
            int sum = 0;
            int cnt = 0;

            for (int i = 1; i <= N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (dq[i].at(j) > 0)
                    {
                        sum += dq[i].at(j);
                        cnt += 1;
                    }
                }
            }

            double avg = (double)sum / (double)cnt;
            // cout << (double)avg << endl;

            for (int i = 1; i <= N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if ((double)dq[i].at(j) > avg)
                    {
                        dq[i].at(j) -= 1;
                    }
                    else if ((double)dq[i].at(j) < avg && dq[i].at(j) != 0)
                    {
                        dq[i].at(j) += 1;
                    }
                }
            }
        }

        // for (int i = 1; i <= N; i++)
        // {
        //     for (int j = 0; j < M; j++)
        //     {
        //         cout << dq[i].at(j) << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }

    int ans = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            ans += dq[i].at(j);
        }
    }

    cout << ans << "\n";
}