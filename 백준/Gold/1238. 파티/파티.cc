#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 10000000

using namespace std;

int N, M, X;
vector<pair<int, int>> myMap[1005];

int dijkstra(int start, int end)
{
    priority_queue<pair<int, int>> pq;
    vector<int> path(1005, MAX);

    pq.push({0, start});
    path[start] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (cost > path[cur])
        {
            if (cur == end)
                return path[end];
            else
                continue;
        }

        for (int i = 0; i < myMap[cur].size(); i++)
        {
            int next = myMap[cur][i].first;
            int ncost = myMap[cur][i].second + cost;

            if (ncost < path[next])
            {
                path[next] = ncost;
                pq.push({-ncost, next});
            }
        }
    }

    return path[end];
}

int main()
{
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++)
    {
        int f, t, w;
        cin >> f >> t >> w;

        myMap[f].push_back({t, w});
    }

    priority_queue<int> list;

    for (int i = 1; i <= N; i++)
    {
        if (i != X)
        {
            int dist = dijkstra(i, X) + dijkstra(X, i);
            list.push(dist);
        }
    }

    cout << list.top() << endl;

    return 0;
}