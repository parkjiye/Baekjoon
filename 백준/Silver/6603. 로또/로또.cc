#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<int> v;
int path[8];

void backtracking(int idx)
{
    if (idx == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << v[path[i]] << " ";
        }
        cout << "\n";
        return;
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (idx == 0 || path[idx - 1] < i)
            {
                path[idx] = i;
                backtracking(idx + 1);
            }
        }
    }
}

int main()
{
    while (1)
    {
        int k;
        int idx = 0;
        cin >> k;

        if (k == 0)
        {
            break;
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                int x;
                cin >> x;

                v.push_back(x);
            }

            sort(v.begin(), v.end());

            backtracking(0);

            cout << "\n";

            v.clear();
        }
    }
}