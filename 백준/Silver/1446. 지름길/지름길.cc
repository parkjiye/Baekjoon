#include <iostream>
#include <vector>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, D;
int dist[10005];

vector<pair<int, int>> myMap[10005];

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost)
        {
            continue;
        }

        for (int i = 0; i < myMap[cur].size(); i++)
        {
            int next = myMap[cur][i].first;
            int ncost = cost + myMap[cur][i].second;

            if (ncost < dist[next])
            {
                dist[next] = ncost;
                pq.push({-ncost, next});
            }
        }
    }
}

int main()
{
    FASTIO();
    cin >> N >> D;

    for (int i = 0; i < N; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        myMap[x].push_back({y, z});
    }

    for (int i = 0; i <= D; i++)
    {
        myMap[i].push_back({i + 1, 1});
    }

    for (int i = 0; i <= 10000; i++)
    {
        dist[i] = 987654321;
    }

    dijkstra();

    cout << dist[D] << "\n";
}