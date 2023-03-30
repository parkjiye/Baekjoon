#include <iostream>
#include <vector>
#define MAX_INT 60000000
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
vector<pair<int, int>> myMap[505];
vector<long long> dist(505, MAX_INT);

bool belman_ford()
{
    dist.resize(N);
    dist[1] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 0; k < myMap[j].size(); k++)
            {
                int next = myMap[j][k].first;
                int cost = myMap[j][k].second;

                if (dist[j] != MAX_INT && dist[next] > dist[j] + cost)
                {
                    dist[next] = dist[j] + cost;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < myMap[i].size(); j++)
        {
            int next = myMap[i][j].first;
            int cost = myMap[i][j].second;

            if (dist[i] != MAX_INT && dist[next] > dist[i] + cost)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    FASTIO();

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;

        myMap[A].push_back({B, C});
    }

    if (belman_ford())
    {
        for (int i = 2; i <= dist.size(); i++)
        {
            if (dist[i] == MAX_INT)
                cout << -1 << "\n";
            else
                cout << dist[i] << "\n";
        }
    }
    else
    {
        cout << -1 << "\n";
    }

    return 0;
}