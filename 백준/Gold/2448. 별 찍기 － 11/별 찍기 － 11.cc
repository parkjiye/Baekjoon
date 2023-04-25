#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

char myMap[3072][6144];

void draw_triangle(int x, int y, int n)
{
    if (n == 3)
    {
        myMap[x][y] = '*';
        myMap[x + 1][y - 1] = '*';
        myMap[x + 1][y + 1] = '*';
        for (int j = y - 2; j <= y + 2; j++)
        {
            myMap[x + 2][j] = '*';
        }

        return;
    }

    draw_triangle(x, y, n / 2);
    draw_triangle(x + n / 2, y - n / 2, n / 2);
    draw_triangle(x + n / 2, y + n / 2, n / 2);
}

int main()
{
    FASTIO();

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N; j++)
        {
            myMap[i][j] = ' ';
        }
    }

    draw_triangle(0, N - 1, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N; j++)
        {
            cout << myMap[i][j];
        }
        cout << endl;
    }

    return 0;
}