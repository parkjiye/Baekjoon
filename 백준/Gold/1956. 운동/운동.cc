#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define INF 1000000000
using namespace std;

int V, E;
int dist[404][404];

int main()
{
    FASTIO();
    cin >> V >> E;

    for (int i = 0; i <= V; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = c;
    }
    // 거쳐 가는 노드
    for (int k = 1; k <= V; k++)
    {
        // 출발 노드
        for (int i = 1; i <= V; i++)
        {
            // 도착 노드
            for (int j = 1; j <= V; j++)
            {
                // 출발노드와 도착 노드가 같지 않은 경우
                if (i != j)
                {
                    // 거쳐 가는 노드와 출발 노드가 같은 경우
                    if (i == k)
                    {
                        dist[i][j] = min(dist[i][j], dist[k][j]);
                    }
                    // 거쳐 가는 노드와 도착 노드가 같은 경우
                    else if (k == j)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k]);
                    }
                    else
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
                else
                {
                    if (dist[i][j] == 0)
                    {
                        dist[i][j] = INF;
                    }
                    if (i != k)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                    if (dist[i][j] >= INF)
                    {
                        dist[i][j] = 0;
                    }
                }
            }
        }
    }

    int answer = INF;

    for (int i = 1; i <= V; i++)
    {
        if (dist[i][i] != 0)
        {
            answer = min(dist[i][i], answer);
        }
    }

    if (answer == INF)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << answer << "\n";
    }
}