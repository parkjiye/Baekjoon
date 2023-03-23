#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int V;

vector<pair<int, int>> myMap[100005];
bool visited[100005];
int dist[100005];

void dfs(int start)
{
    for (int i = 0; i < myMap[start].size(); i++)
    {
        if (!visited[myMap[start][i].first])
        {
            visited[myMap[start][i].first] = true;
            dist[myMap[start][i].first] = myMap[start][i].second + dist[start];
            dfs(myMap[start][i].first);
        }
    }
}

int main()
{
    cin >> V;
    int v1, v2, val;

    for (int i = 0; i < V; i++)
    {
        cin >> v1;
        while (cin >> v2 && v2 != -1)
        {
            cin >> val;
            myMap[v1].push_back({v2, val});
            // tree[v2].push_back({v1, val});

            // cout << v2 << " " << val << endl;
        }
    }

    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    dist[1] = 0;
    visited[1] = 0;
    dfs(1);

    int path1 = -1;
    int point;

    for (int i = 2; i <= V; i++)
    {
        if (path1 < dist[i])
        {
            path1 = dist[i];
            point = i;
        }
    }

    // cout << path1 << endl;

    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    dist[point] = 0;
    visited[point] = 0;
    dfs(point);

    int path2 = -1;

    for (int i = 1; i <= V; i++)
    {
        if (path2 < dist[i] && i != point)
        {
            path2 = dist[i];
        }
    }

    cout << path2 << endl;

    // cout << path1 + path2 << endl;

    return 0;
}