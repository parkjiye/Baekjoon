#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
vector<pair<int, int>> myGraph[1005];
bool visited[1005];

int bfs(int from, int dst)
{
    queue<pair<int, int>> q;
    memset(visited, 0, sizeof(visited));
    q.push({from, 0});
    visited[from] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (cur == dst)
        {
            return dist;
        }

        for (int i = 0; i < myGraph[cur].size(); i++)
        {
            int next = myGraph[cur][i].first;

            if (!visited[next])
            {
                q.push({next, myGraph[cur][i].second + dist});
                visited[next] = true;
            }
        }
    }
}

int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 0; i < N - 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        myGraph[x].push_back({y, z});
        myGraph[y].push_back({x, z});
    }

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        cout << bfs(x, y) << endl;
    }
}