#include <iostream>
#include <vector>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_INT 300000000

using namespace std;

int N, M, W;

vector<pair<int, int>> myMap[505];

int belman_ford(int start)
{
    vector<long long> path(505, MAX_INT);

    path[start] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 0; k < myMap[j].size(); k++)
            {
                int next = myMap[j][k].first;
                int cost = myMap[j][k].second;

                if (path[next] > cost + path[j])
                {
                    path[next] = cost + path[j];
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

            if (path[next] > cost + path[i])
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

    int test_case;
    cin >> test_case;

    for (int t = 0; t < test_case; t++)
    {
        memset(myMap, 0, sizeof(myMap));

        cin >> N >> M >> W;

        for (int i = 0; i < M; i++)
        {
            int f, t, c;
            cin >> f >> t >> c;

            myMap[f].push_back({t, c});
            myMap[t].push_back({f, c});
        }

        for (int i = 0; i < W; i++)
        {
            int f, t, c;
            cin >> f >> t >> c;

            myMap[f].push_back({t, -c});
        }

        bool ispossible = false;

        if (belman_ford(1))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}