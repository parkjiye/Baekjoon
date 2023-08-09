#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int path[8] = {
    0,
};

void back_tracking(int idx)
{
    if (idx == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << path[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            if (idx == 0 || path[idx] <= i)
            {
                path[idx] = i;
                back_tracking(idx + 1);
                path[idx] = 0;
            }
        }
    }
}

int main()
{
    FASTIO();
    cin >> N >> M;
    back_tracking(0);
}