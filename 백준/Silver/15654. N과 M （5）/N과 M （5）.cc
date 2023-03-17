#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
int path[10];
bool selected[10];

void backtracking(int idx)
{
    if (idx == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[path[i]] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (selected[i])
                continue;
            selected[i] = true;
            path[idx] = i;
            backtracking(idx + 1);
            selected[i] = false;
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

    backtracking(0);

    return 0;
}