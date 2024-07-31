#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int arr[305][305];

int main()
{
    FASTIO();
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;

            arr[i][j] = x;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == 0 && j != 0)
            {
                arr[i][j] += arr[i][j - 1];
            }
            else if (j == 0 && i != 0)
            {
                arr[i][j] += arr[i - 1][j];
            }
            else if (i != 0 && j != 0)
            {
                arr[i][j] = arr[i][j] + arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
            }
        }
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;

        int result = arr[x2][y2];
        if (x1 > 0)
            result -= arr[x1 - 1][y2];
        if (y1 > 0)
            result -= arr[x2][y1 - 1];
        if (x1 > 0 && y1 > 0)
            result += arr[x1 - 1][y1 - 1];

        cout << result << "\n";
    }
}