#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> v;
vector<int> path(10, 0);

void backtracking(int idx)
{
    if (idx == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << v[path[i]] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (idx == 0 || path[idx - 1] <= i)
            {
                path[idx] = i;
                backtracking(idx + 1);
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }

    sort(v.begin(), v.end());

    backtracking(0);

    return 0;
}