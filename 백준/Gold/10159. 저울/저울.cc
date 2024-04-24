#include <iostream>
#include <climits>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int myMap[105][105];

int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            myMap[i][j] = -1;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        myMap[x][y] = 1;
        myMap[y][x] = 2;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                if (i != j)
                {
                    if (myMap[j][i] == myMap[i][k] && myMap[j][i] != -1)
                    {
                        myMap[j][k] = myMap[i][k];
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        int cnt = 0;

        for (int j = 1; j <= N; j++)
        {
            if (j != i && myMap[i][j] == -1)
            {
                cnt += 1;
            }
        }
        cout << cnt << "\n";
    }
}