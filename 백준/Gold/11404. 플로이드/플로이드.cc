#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_INT 50000000000
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
vector<pair<long, long>> myMap[101];
long dist[105][105];

void floyd()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (dist[i][j] == MAX_INT)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = MAX_INT;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        long a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
    }

    floyd();

    return 0;
}
