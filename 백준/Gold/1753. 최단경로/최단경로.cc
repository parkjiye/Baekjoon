#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int V, E;
int start;
vector<pair<int, int>> myGraph[20005];
vector<int> path(20005, 3000000);

void dijkstra(int start)
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
            continue;

        for (int i = 0; i < myGraph[cur].size(); i++)
        {
            int next = myGraph[cur][i].first;
            int ncost = myGraph[cur][i].second + cost;

            if (ncost < path[next])
            {
                pq.push({-ncost, next});
                path[next] = ncost;
            }
        }
    }
}

int main()
{
    FASTIO();
    cin >> V >> E;
    cin >> start;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        myGraph[u].push_back({v, w});
    }

    dijkstra(start);

    for (int i = 1; i <= V; i++)
    {
        if (path[i] == 3000000)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << path[i] << "\n";
        }
    }

    return 0;
}