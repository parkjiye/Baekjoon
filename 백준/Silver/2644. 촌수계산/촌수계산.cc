#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector<int> myMap[101];
bool visited[101];
int dist[101];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < myMap[cur].size(); i++)
        {
            if (!visited[myMap[cur][i]])
            {
                q.push(myMap[cur][i]);
                visited[myMap[cur][i]] = true;
                dist[myMap[cur][i]] = dist[cur] + 1;
            }
        }
    }
}

int main()
{
    cin >> N;

    int a, b;
    cin >> a >> b;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        myMap[x].push_back(y);
        myMap[y].push_back(x);
    }

    bfs(a);

    if (!visited[b])
    {
        cout << -1 << "\n";
        return 0;
    }
    else
    {
        cout << dist[b] << "\n";
        return 0;
    }
}