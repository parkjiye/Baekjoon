#include <iostream>
#include <vector>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int myMap[10][10];

int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, 1, -1};

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y) {}
    p() {}
};

bool possible[10];

void check_numbers(p cur)
{
    memset(possible, 0, sizeof(possible));

    for (int k = 1; k <= 8; k++)
    {
        int next_x = (cur.x + k) % 9;

        possible[myMap[next_x][cur.y]] = true;
    }

    for (int k = 1; k <= 8; k++)
    {
        int next_y = (cur.y + k) % 9;

        possible[myMap[cur.x][next_y]] = true;
    }

    if (cur.x % 3 == 0 && cur.y % 3 == 0)
    {
        possible[myMap[cur.x + 1][cur.y + 1]] = true;
        possible[myMap[cur.x + 1][cur.y + 2]] = true;
        possible[myMap[cur.x + 2][cur.y + 1]] = true;
        possible[myMap[cur.x + 2][cur.y + 2]] = true;
    }
    else if (cur.x % 3 == 0 && cur.y % 3 == 1)
    {
        possible[myMap[cur.x + 1][cur.y - 1]] = true;
        possible[myMap[cur.x + 1][cur.y + 1]] = true;
        possible[myMap[cur.x + 2][cur.y - 1]] = true;
        possible[myMap[cur.x + 2][cur.y + 1]] = true;
    }
    else if (cur.x % 3 == 0 && cur.y % 3 == 2)
    {
        possible[myMap[cur.x + 1][cur.y - 1]] = true;
        possible[myMap[cur.x + 1][cur.y - 2]] = true;
        possible[myMap[cur.x + 2][cur.y - 1]] = true;
        possible[myMap[cur.x + 2][cur.y - 2]] = true;
    }
    else if (cur.x % 3 == 1 && cur.y % 3 == 0)
    {
        possible[myMap[cur.x - 1][cur.y + 1]] = true;
        possible[myMap[cur.x - 1][cur.y + 2]] = true;
        possible[myMap[cur.x + 1][cur.y + 1]] = true;
        possible[myMap[cur.x + 1][cur.y + 2]] = true;
    }
    else if (cur.x % 3 == 1 && cur.y % 3 == 1)
    {
        possible[myMap[cur.x - 1][cur.y - 1]] = true;
        possible[myMap[cur.x - 1][cur.y + 1]] = true;
        possible[myMap[cur.x + 1][cur.y - 1]] = true;
        possible[myMap[cur.x + 1][cur.y + 1]] = true;
    }
    else if (cur.x % 3 == 1 && cur.y % 3 == 2)
    {
        possible[myMap[cur.x - 1][cur.y - 1]] = true;
        possible[myMap[cur.x - 1][cur.y - 2]] = true;
        possible[myMap[cur.x + 1][cur.y - 1]] = true;
        possible[myMap[cur.x + 1][cur.y - 2]] = true;
    }
    else if (cur.x % 3 == 2 && cur.y % 3 == 0)
    {
        possible[myMap[cur.x - 1][cur.y + 1]] = true;
        possible[myMap[cur.x - 1][cur.y + 2]] = true;
        possible[myMap[cur.x - 2][cur.y + 1]] = true;
        possible[myMap[cur.x - 2][cur.y + 2]] = true;
    }
    else if (cur.x % 3 == 2 && cur.y % 3 == 1)
    {
        possible[myMap[cur.x - 1][cur.y - 1]] = true;
        possible[myMap[cur.x - 1][cur.y + 1]] = true;
        possible[myMap[cur.x - 2][cur.y - 1]] = true;
        possible[myMap[cur.x - 2][cur.y + 1]] = true;
    }
    else if (cur.x % 3 == 2 && cur.y % 3 == 2)
    {
        possible[myMap[cur.x - 1][cur.y - 1]] = true;
        possible[myMap[cur.x - 1][cur.y - 2]] = true;
        possible[myMap[cur.x - 2][cur.y - 1]] = true;
        possible[myMap[cur.x - 2][cur.y - 2]] = true;
    }
}

bool found = false;
vector<p> v;

int sudoku(int idx)
{
    p cur = v[idx];

    if (idx == v.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << myMap[i][j];
            }
            cout << endl;
        }

        found = true;
        return 0;
    }

    for (int i = 1; i <= 9; i++)
    {

        if (found)
        {
            return 0;
        }

        check_numbers(cur);

        if (!possible[i])
        {
            myMap[cur.x][cur.y] = i;

            sudoku(idx + 1);
            myMap[cur.x][cur.y] = 0;
        }
    }
    return 0;
}

int main()
{
    FASTIO();

    for (int i = 0; i < 9; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < 9; j++)
        {
            myMap[i][j] = s[j] - '0';

            if (myMap[i][j] == 0)
            {
                v.push_back(p(i, j));
            }
        }
    }

    sudoku(0);
}