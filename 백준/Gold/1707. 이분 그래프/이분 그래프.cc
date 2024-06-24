#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int K, V, E;
bool visited[20005];
bool color[20005];

int main()
{
    FASTIO();

    cin >> K;

    for (int k = 0; k < K; k++)
    {
        cin >> V >> E;
        vector<int> myGraph[20005];

        memset(visited, 0, sizeof(visited));
        memset(color, 0, sizeof(color));

        for (int i = 0; i < E; i++)
        {
            int x, y;
            cin >> x >> y;
            myGraph[x].push_back(y);
            myGraph[y].push_back(x);
        }

        queue<int> q;
        bool isBipartite = true;

        for (int v = 1; v <= V; v++)
        {

            if (!visited[v])
            {
                visited[v] = true;
                color[v] = true;
                q.push(v);
            }

            while (!q.empty())
            {
                if (!isBipartite)
                {
                    break;
                }
                int cur = q.front();
                q.pop();

                for (int i = 0; i < myGraph[cur].size(); i++)
                {
                    if (!visited[myGraph[cur][i]])
                    {
                        color[myGraph[cur][i]] = !color[cur];
                        visited[myGraph[cur][i]] = true;
                        q.push(myGraph[cur][i]);
                    }
                    else
                    {
                        if (color[myGraph[cur][i]] == color[cur])
                        {
                            cout << "NO" << "\n";
                            isBipartite = false;
                            break;
                        }
                    }
                }
            }
        }

        if (isBipartite)
        {
            cout << "YES" << "\n";
        }
    }
}