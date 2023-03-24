#include <iostream>
#include <string.h>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<long long> myMap[1025];
vector<long long> onemap[1025];

int main()
{
    FASTIO();

    memset(myMap, 0, sizeof(myMap));

    int N, M;
    cin >> N >> M;
    int x1, y1, x2, y2;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;

            myMap[i].push_back(x);
            onemap[i].push_back(x);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 && j != 0)
            {
                myMap[i][j] = myMap[i][j - 1] + myMap[i][j];
            }
            else if (i != 0 && j == 0)
            {
                myMap[i][j] = myMap[i - 1][j] + myMap[i][j];
            }
            else if (i == 0 && j == 0)
            {
                continue;
            }
            else
            {
                myMap[i][j] = myMap[i - 1][j] + myMap[i][j - 1] + myMap[i][j] - myMap[i - 1][j - 1];
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        x1--;
        x2--;
        y1--;
        y2--;

        if (x1 == x2 && y1 == y2)
        {
            cout << onemap[x1][y1] << "\n";
        }
        else if (x1 == 0 && y1 == 0)
        {
            cout << myMap[x2][y2] << "\n";
        }
        else if (x1 == 0 && y1 != 0)
        {
            cout << myMap[x2][y2] - myMap[x2][y1 - 1] << "\n";
        }
        else if (x1 != 0 && y1 == 0)
        {
            cout << myMap[x2][y2] - myMap[x1 - 1][y2] << "\n";
        }
        else
        {
            cout << myMap[x2][y2] - myMap[x2][y1 - 1] - myMap[x1 - 1][y2] + myMap[x1 - 1][y1 - 1] << "\n";
        }
    }

    return 0;
}