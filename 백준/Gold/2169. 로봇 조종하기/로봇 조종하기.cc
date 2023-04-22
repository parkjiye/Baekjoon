#include <iostream>
#include <queue>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int myMap[1005][1005];
int value[1005][1005];
int temp[1005][2];

int dx[4] = {0, 0, 1};
int dy[4] = {1, -1, 0};

int main()
{
    cin >> N >> M;
    memset(myMap, 0, sizeof(myMap));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = x;
        }
    }

    value[0][0] = myMap[0][0];

    for (int i = 1; i < M; i++)
    {
        value[0][i] = value[0][i - 1] + myMap[0][i];
    }

    for (int i = 1; i < N; i++)
    {
        temp[0][0] = value[i - 1][0] + myMap[i][0];
        temp[M - 1][1] = value[i - 1][M - 1] + myMap[i][M - 1];

        for (int j = 1; j < M; j++)
        {
            temp[j][0] = max(value[i - 1][j], temp[j - 1][0]) + myMap[i][j];
        }

        for (int j = M - 2; j >= 0; j--)
        {
            temp[j][1] = max(value[i - 1][j], temp[j + 1][1]) + myMap[i][j];
        }

        for (int j = 0; j < M; j++)
        {
            value[i][j] = max(temp[j][0], temp[j][1]);
        }
    }

    cout << value[N - 1][M - 1] << endl;

    return 0;
}