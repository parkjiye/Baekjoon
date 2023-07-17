#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct holloween
{
    int candy;
    int cnt;

    holloween(int candy, int cnt) : candy(candy), cnt(cnt) {}
    holloween() {}
};

int N, M, K;

vector<holloween> v;
int dp[3005][2];

int pick()
{
    for (int i = 0; i < v.size(); i++)
    {
        int cur_cnt = v[i].cnt;
        int cur_candy = v[i].candy;

        for (int j = 0; j < K; j++)
        {
            if (cur_cnt > j)
            {
                dp[j][1] = dp[j][0];
            }
            else
            {
                dp[j][1] = max(dp[j][0], dp[j - cur_cnt][0] + cur_candy);
            }
        }

        for (int j = 0; j < K; j++)
        {
            dp[j][0] = dp[j][1];
        }
    }

    return dp[K - 1][0];
}

int main()
{
    FASTIO();
    cin >> N >> M >> K;

    int candy[30005];
    bool visited[30005];
    vector<int> myMap[30005];

    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        candy[i] = x;
    }

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        myMap[x].push_back(y);
        myMap[y].push_back(x);
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            holloween h = holloween(0, 0);

            queue<int> q;
            q.push(i);
            visited[i] = true;

            h.candy += candy[i];
            h.cnt += 1;

            while (!q.empty())
            {
                int cur = q.front();
                q.pop();

                for (int k = 0; k < myMap[cur].size(); k++)
                {
                    int next = myMap[cur][k];

                    if (!visited[next])
                    {
                        h.candy += candy[next];
                        h.cnt += 1;
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }

            v.push_back(h);
        }
    }

    cout << pick() << endl;
}