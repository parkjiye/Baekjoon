#include <iostream>
#include <string.h>

using namespace std;

long long N, M;

long long myMap[10][10];
long long rst[10][10];

void mul(long long N, long long A[10][10], long long B[10][10])
{
    long long temp[10][10];
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                temp[i][j] += (A[i][k] * B[k][j]);
            }
            temp[i][j] %= 1000;
        }
    }

    memcpy(rst, temp, sizeof(temp));
}

void nmul(long long N, long long A[10][10], long long B[10][10])
{
    long long temp[10][10];
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                temp[i][j] += (A[i][k] * B[k][j]);
            }
            temp[i][j] %= 1000;
        }
    }

    memcpy(myMap, temp, sizeof(temp));
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            long long x;
            cin >> x;
            myMap[i][j] = x;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            myMap[i][j] %= 1000;
        }
    }

    memset(rst, 0, sizeof(rst));

    for (int i = 0; i < N; i++)
    {
        rst[i][i] = 1;
    }

    while (M != 0)
    {
        if (M % 2 == 1)
        {
            mul(N, rst, myMap);
        }
        nmul(N, myMap, myMap);
        M >>= 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << rst[i][j] << " ";
        }
        cout << endl;
    }
}