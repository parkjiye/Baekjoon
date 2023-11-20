#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y) {}
    p() {}
};

char myMap[10000][10000];

void print_blank(int n, p cur)
{
    for (int i = cur.x; i < cur.x + n; i++)
    {
        for (int j = cur.y; j < cur.y + n; j++)
        {
            myMap[i][j] = ' ';
        }
    }
}

void print_start(int n, p cur)
{
    if (n > 3)
    {
        print_start(n / 3, p(cur.x, cur.y));
        print_start(n / 3, p(cur.x, cur.y + n / 3));
        print_start(n / 3, p(cur.x, cur.y + (n / 3) * 2));
        print_start(n / 3, p(cur.x + n / 3, cur.y));
        print_blank(n / 3, p(cur.x + n / 3, cur.y + n / 3));
        print_start(n / 3, p(cur.x + n / 3, cur.y + n / 3 * 2));
        print_start(n / 3, p(cur.x + n / 3 * 2, cur.y));
        print_start(n / 3, p(cur.x + n / 3 * 2, cur.y + n / 3));
        print_start(n / 3, p(cur.x + n / 3 * 2, cur.y + n / 3 * 2));
    }
    else
    {
        for (int i = cur.x; i < cur.x + n; i++)
        {
            for (int j = cur.y; j < cur.y + n; j++)
            {
                if (i % 3 == 1 && j % 3 == 1)
                {
                    myMap[i][j] = ' ';
                }
                else
                {
                    myMap[i][j] = '*';
                }
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    print_start(N, p(0, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << myMap[i][j];
        }
        cout << "\n";
    }
}