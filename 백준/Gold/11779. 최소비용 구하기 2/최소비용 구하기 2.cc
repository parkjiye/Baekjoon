#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> myGraph[1005];
int dist[1005];
int route[1005];

int n, m;
int start, dest;

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > dist[cur])
            continue;

        for (int i = 0; i < myGraph[cur].size(); i++)
        {
            int next = myGraph[cur][i].first;
            int ncost = cost + myGraph[cur][i].second;

            if (ncost < dist[next])
            {
                dist[next] = ncost;
                pq.push(make_pair(-ncost, next));
                route[next] = cur;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;

        myGraph[x].push_back(make_pair(y, c));
    }

    for (int i = 1; i <= n; i++)
    {
        dist[i] = 987654321;
    }

    cin >> start >> dest;

    dijkstra();

    cout << dist[dest] << endl;

    int temp = dest;
    vector<int> ans;

    while (temp)
    {
        ans.push_back(temp);
        temp = route[temp];
    }

    cout << ans.size() << endl;

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}