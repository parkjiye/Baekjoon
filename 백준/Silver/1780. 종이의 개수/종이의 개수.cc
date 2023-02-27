#include <iostream>

using namespace std;

int myMap[2200][2200];

int zero;
int minone;
int one;

void divide(int N, int x, int y)
{

    int check = myMap[x][y];
    bool same = true;

    for (int i = x; i < x + N; i++)
    {
        for (int j = y; j < y + N; j++)
        {
            if (myMap[i][j] == check)
            {
                continue;
            }
            else
            {
                same = false;
                break;
            }
        }
    }

    if (same || N == 1)
    {
        if (check == 0)
            zero += 1;
        else if (check == 1)
            one += 1;
        else
            minone += 1;
    }
    else
    {
        divide(N / 3, x, y);
        divide(N / 3, x, y + 2 * (N / 3));
        divide(N / 3, x, y + N / 3);

        divide(N / 3, x + N / 3, y);
        divide(N / 3, x + N / 3, y + N / 3);
        divide(N / 3, x + N / 3, y + 2 * (N / 3));

        divide(N / 3, x + 2 * (N / 3), y);
        divide(N / 3, x + 2 * (N / 3), y + N / 3);
        divide(N / 3, x + 2 * (N / 3), y + 2 * (N / 3));
    }

    // cout << N << " " << zero << " " << one << " " << minone << endl;

    return;
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;

            myMap[i][j] = num;
        }
    }

    divide(N, 0, 0);

    cout << minone << endl;
    cout << zero << endl;
    cout << one << endl;
}