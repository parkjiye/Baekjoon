#include <iostream>
#include <vector>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_INT 10000

using namespace std;

int N, M, R;

vector<pair<int, int>> myMap[101];
int item[101];

int dijkstra(int start)
{
    int dist[110];

    for (int i = 0; i < 105; i++)
    {
        dist[i] = MAX_INT;
    }

    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (dist[cur] < cost)
        {
            continue;
        }

        for (int k = 0; k < myMap[cur].size(); k++)
        {
            int next = myMap[cur][k].first;
            int n_cost = myMap[cur][k].second + cost;

            if (n_cost < dist[next])
            {
                pq.push({-n_cost, next});
                dist[next] = n_cost;
            }
        }
    }

    int items = 0;

    for (int k = 1; k <= N; k++)
    {
        if (dist[k] <= M)
        {
            items += item[k];
        }
    }

    return items;
}

int main()
{
    cin >> N >> M >> R;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        item[i + 1] = x;
    }

    for (int i = 0; i < R; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;

        myMap[a].push_back({b, l});
        myMap[b].push_back({a, l});
    }

    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        int temp = dijkstra(i);

        if (temp > answer)
        {
            answer = temp;
        }
    }

    cout << answer << endl;
    return 0;
}