#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int path[8] = {
    0,
};
bool visited[8] = {
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

        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            path[idx] = i;
            back_tracking(idx + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    FASTIO();
    cin >> N >> M;

    back_tracking(0);
}