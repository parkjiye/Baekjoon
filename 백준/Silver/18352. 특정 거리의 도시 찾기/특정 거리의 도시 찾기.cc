#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M, K, X;
int dist[300005];
bool visited[300005];
vector<int> myGraph[300005];

void bfs(int start)
{
    memset(dist, 0, sizeof(dist));
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < myGraph[cur].size(); i++)
        {
            int next = myGraph[cur][i];

            if (!visited[next])
            {
                dist[next] = dist[cur] + 1;
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    FASTIO();
    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        myGraph[x].push_back(y);
    }

    bfs(X);

    int cnt = 0;

    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == K)
        {
            cout << i << "\n";
            cnt += 1;
        }
    }

    if (cnt == 0)
    {
        cout << -1 << "\n";
    }
}