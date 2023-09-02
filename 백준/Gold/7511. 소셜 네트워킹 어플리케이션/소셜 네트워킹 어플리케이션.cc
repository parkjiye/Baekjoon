#include <iostream>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int T, N, K, M;
int users[1000005];

int findParents(int idx)
{
    if (users[idx] == idx)
    {
        return idx;
    }
    else
    {
        return users[idx] = findParents(users[idx]);
    }
}

int main()
{
    FASTIO();
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cin >> N;
        memset(users, 0, sizeof(users));

        cin >> K;
        int cnt = 1;

        for (int i = 0; i < N; i++)
        {
            users[i] = i;
        }

        for (int k = 0; k < K; k++)
        {
            int a, b;
            cin >> a >> b;

            a = findParents(a);
            b = findParents(b);

            if (a < b)
            {
                users[b] = a;
            }
            else
            {
                users[a] = b;
            }
        }

        cin >> M;

        cout << "Scenario " << t << ":"
             << "\n";

        for (int m = 0; m < M; m++)
        {
            int u, v;
            cin >> u >> v;

            if (findParents(u) == findParents(v))
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }

        if (t != T)
        {
            cout << "\n";
        }
    }
}