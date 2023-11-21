#include <iostream>
#include <vector>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int myMap[10][10];
int dx[9][4] = {{1, 1, 2, 2}, {1, 1, 2, 2}, {1, 1, 2, 2}, {-1, -1, 1, 1}, {-1, -1, 1, 1}, {-1, -1, 1, 1}, {-1, -1, -2, -2}, {-1, -1, -2, -2}, {-1, -1, -2, -2}};
int dy[9][4] = {{1, 2, 1, 2}, {-1, 1, -1, 1}, {-1, -2, -1, -2}, {1, 2, 1, 2}, {-1, 1, -1, 1}, {-1, -2, -1, -2}, {1, 2, 1, 2}, {-1, 1, -1, 1}, {-1, -2, -1, -2}};
struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y) {}
};

vector<p> v;
bool found = false;

void sudoku(int n)
{
    if (n >= v.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << myMap[i][j] << " ";
            }
            cout << "\n";
        }
        found = true;
        return;
    }

    p cur = v[n];
    bool occupied[10] = {
        0,
    };

    // 가로 세로
    for (int i = 0; i < 9; i++)
    {
        if (myMap[cur.x][i] != 0)
        {
            occupied[myMap[cur.x][i]] = true;
        }

        if (myMap[i][cur.y] != 0)
        {
            occupied[myMap[i][cur.y]] = true;
        }
    }

    int k;

    // 정사각형
    if (cur.x % 3 == 0 && cur.y % 3 == 0)
    {
        k = 0;
    }
    else if (cur.x % 3 == 0 && cur.y % 3 == 1)
    {
        k = 1;
    }
    else if (cur.x % 3 == 0 && cur.y % 3 == 2)
    {
        k = 2;
    }
    else if (cur.x % 3 == 1 && cur.y % 3 == 0)
    {
        k = 3;
    }
    else if (cur.x % 3 == 1 && cur.y % 3 == 1)
    {
        k = 4;
    }
    else if (cur.x % 3 == 1 && cur.y % 3 == 2)
    {
        k = 5;
    }
    else if (cur.x % 3 == 2 && cur.y % 3 == 0)
    {
        k = 6;
    }
    else if (cur.x % 3 == 2 && cur.y % 3 == 1)
    {
        k = 7;
    }
    else
    {
        k = 8;
    }

    for (int i = 0; i < 4; i++)
    {
        int next_x = cur.x + dx[k][i];
        int next_y = cur.y + dy[k][i];

        if (myMap[next_x][next_y] != 0)
        {
            occupied[myMap[next_x][next_y]] = true;
        }
    }

    for (int i = 1; i <= 9; i++)
    {
        if (!occupied[i])
        {
            myMap[cur.x][cur.y] = i;
            sudoku(n + 1);
            if (found)
            {
                return;
            }
            myMap[cur.x][cur.y] = 0;
        }
    }
}

int main()
{
    FASTIO();

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = x;

            if (x == 0)
            {
                v.push_back(p(i, j));
            }
        }
    }

    sudoku(0);
}