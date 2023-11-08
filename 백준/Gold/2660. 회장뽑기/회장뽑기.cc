#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define INF 1000000000

using namespace std;

int N;
int myMap[55][55];

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            myMap[i][j] = INF;
        }
        myMap[i][i] = 0;
    }

    while (1)
    {
        int x, y;
        cin >> x >> y;

        if (x == -1 && y == -1)
        {
            break;
        }

        myMap[x][y] = 1;
        myMap[y][x] = 1;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (myMap[i][j] > myMap[i][k] + myMap[k][j])
                {
                    myMap[i][j] = myMap[i][k] + myMap[k][j];
                }
            }
        }
    }

    vector<int> v;
    int min_score = INF;

    for (int i = 1; i <= N; i++)
    {
        int max = 0;

        for (int j = 1; j <= N; j++)
        {
            if (max < myMap[i][j])
            {
                max = myMap[i][j];
            }
        }

        if (min_score > max)
        {
            min_score = max;
            v.clear();
            v.push_back(i);
        }
        else if (min_score == max)
        {
            v.push_back(i);
        }
    }

    cout << min_score << " " << v.size() << "\n";

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    // cout << "\n";
}