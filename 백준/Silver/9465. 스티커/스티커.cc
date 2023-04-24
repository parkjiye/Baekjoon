#include <iostream>

using namespace std;

int N, T;
int myMap[2][100000];
int answer;

int main()
{
    cin >> T;
    answer = 0;

    for (int t = 0; t < T; t++)
    {
        cin >> N;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int x;
                cin >> x;

                myMap[i][j] = x;
            }
        }

        myMap[0][1] += myMap[1][0];
        myMap[1][1] += myMap[0][0];

        for (int i = 2; i < N; i++)
        {
            myMap[0][i] += max(max(myMap[0][i - 2], myMap[1][i - 2]), myMap[1][i - 1]);
            myMap[1][i] += max(max(myMap[0][i - 2], myMap[1][i - 2]), myMap[0][i - 1]);
        }

        cout << max(myMap[0][N - 1], myMap[1][N - 1]) << endl;
    }

    return 0;
}