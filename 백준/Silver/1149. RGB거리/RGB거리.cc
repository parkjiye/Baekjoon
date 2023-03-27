#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

int myMap[1000][3];

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int r, g, b;
        cin >> r >> g >> b;

        myMap[i][0] = r;
        myMap[i][1] = g;
        myMap[i][2] = b;
    }

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
            continue;
        else
        {
            myMap[i][0] += min(myMap[i - 1][1], myMap[i - 1][2]);
            myMap[i][1] += min(myMap[i - 1][0], myMap[i - 1][2]);
            myMap[i][2] += min(myMap[i - 1][0], myMap[i - 1][1]);
        }
    }

    int answer = min(myMap[N - 1][0], min(myMap[N - 1][1], myMap[N - 1][2]));

    cout << answer << endl;
}