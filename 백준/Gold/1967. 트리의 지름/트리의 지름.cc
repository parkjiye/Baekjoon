#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int N;
vector<pair<int, int>> myGraph[10005];
bool visited[10005];

int dfs(int start)
{
    visited[start] = true;
    int max_weight = 0;

    for (int i = 0; i < myGraph[start].size(); i++)
    {
        if (!visited[myGraph[start][i].first])
        {
            int cost = myGraph[start][i].second + dfs(myGraph[start][i].first);
            if (cost > max_weight)
                max_weight = cost;
        }
    }

    return max_weight;
}

int main()
{
    FASTIO();

    cin >> N;

    if (N == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < N - 1; i++)
    {
        int f, t, w;
        cin >> f >> t >> w;
        myGraph[f].push_back({t, w});
        myGraph[t].push_back({f, w});
    }

    priority_queue<int> pq;

    for (int i = 1; i <= N; i++)
    {
        if (myGraph[i].size() >= 2)
        {
            memset(visited, 0, sizeof(visited));
            visited[i] = true;
            vector<int> v;
            for (int j = 0; j < myGraph[i].size(); j++)
            {
                v.push_back(myGraph[i][j].second + dfs(myGraph[i][j].first));
            }

            sort(v.begin(), v.end());

            pq.push(v[myGraph[i].size() - 1] + v[myGraph[i].size() - 2]);
        }
    }

    cout << pq.top() << endl;

    return 0;
}