#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int board[5][5][100005];
vector<int> v;

int check_dir(int l, int r)
{
    if (l == 0)
    {
        return 2;
    }
    if (l == r)
    {
        return 1;
    }
    if (abs(l - r) == 2)
    {
        return 4;
    }
    else
    {
        return 3;
    }
}

int dance(int left, int right, int target)
{
    if (target == v.size())
    {
        return 0;
    }

    if (board[left][right][target] != -1)
    {
        return board[left][right][target];
    }

    int goleft = check_dir(left, v[target]) + dance(v[target], right, target + 1);
    int goright = check_dir(right, v[target]) + dance(left, v[target], target + 1);

    return board[left][right][target] = min(goleft, goright);
}

int main()
{
    FASTIO();

    while (1)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            break;
        }
        v.push_back(x);
    }

    memset(board, -1, sizeof(board));

    cout << dance(0, 0, 0) << "\n";
}