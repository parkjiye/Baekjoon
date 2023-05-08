#include <iostream>
using namespace std;

long long first[150][150];
long long second[150][150];

int main()
{
    int n, m;
    cin >> n >> m;

    first[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j - 1 >= 0)
            {
                first[i][j] = first[i - 1][j - 1];
                second[i][j] = second[i - 1][j - 1];
            }

            first[i][j] += first[i - 1][j];
            second[i][j] += second[i - 1][j];

            if (first[i][j] >= 10000000000000000)
            {
                second[i][j] += first[i][j] / 10000000000000000;
                first[i][j] %= 10000000000000000;
            }
        }
    }

    if (second[n][m] != 0)
    {
        printf("%lld%016lld\n", second[n][m], first[n][m]);
    }
    else
    {
        cout << first[n][m] << endl;
    }

    return 0;
}
