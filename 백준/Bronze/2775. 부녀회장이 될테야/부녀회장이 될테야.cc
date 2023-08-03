#include <iostream>

using namespace std;

int apt[15][15];

int check_apt(int k, int n)
{
    if (k == 0)
    {
        apt[0][n] = n;
        return n;
    }

    if (apt[k][n] != 0)
    {
        return apt[k][n];
    }

    for (int i = 1; i <= n; i++)
    {
        apt[k][n] += check_apt(k - 1, i);
    }

    return apt[k][n];
}

int main()
{

    int T, k, n;
    cin >> T;

    for (int i = 0; i <= 14; i++)
    {
        for (int j = 1; j <= 14; j++)
        {
            apt[i][j] = 0;
        }
    }

    for (int t = 0; t < T; t++)
    {
        cin >> k >> n;

        cout << check_apt(k, n) << endl;
    }
}