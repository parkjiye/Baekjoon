#include <iostream>
#include <vector>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define INF 100000000

using namespace std;

int N, M;
vector<pair<int, int>> myGraph[1005];
vector<int> path;

int dijkstra(int start, int dest)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    path[start] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;

        pq.pop();

        if (cost > path[cur])
        {
            if (cur == dest)
                return path[dest];
            else
                continue;
        }

        for (int i = 0; i < myGraph[cur].size(); i++)
        {
            int next = myGraph[cur][i].first;
            int ncost = cost + myGraph[cur][i].second;

            if (path[next] > ncost)
            {
                path[next] = ncost;
                pq.push({-ncost, next});
            }
        }
    }

    return path[dest];
}

int main()
{
    FASTIO();

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int f, t, w;
        cin >> f >> t >> w;

        myGraph[f].push_back({t, w});
    }

    int start, dest;

    cin >> start >> dest;

    path.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        path[i] = INF;
    }

    cout << dijkstra(start, dest) << endl;

    return 0;
}