#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int N, M;
vector<int> path(10, 0);
vector<int> arr;
bool visited[10];

set<vector<int>> s;

void back_tracking(int idx)
{
    if (idx == M)
    {

        if (s.find(path) == s.end())
        {
            s.insert(path);
            for (int i = 0; i < M; i++)
            {
                cout << path[i] << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                path[idx] = arr[i];
                back_tracking(idx + 1);
                visited[i] = false;
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
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    back_tracking(0);

    return 0;
}