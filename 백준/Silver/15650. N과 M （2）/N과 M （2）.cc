#include <iostream>

using namespace std;

int N, M;

int path[8];

void combination(int idx)
{
    if (idx == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            if (idx == 0 || path[idx - 1] < i)
            {
                path[idx] = i;
                combination(idx + 1);
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    combination(0);
    return 0;
}