#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int users[300005];

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
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        users[i] = i;
    }

    for (int i = 0; i < N - 2; i++)
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

    int u = findParents(1);

    for (int i = 2; i <= N; i++)
    {
        if (u != findParents(i))
        {
            cout << 1 << " " << i << endl;
            return 0;
        }
    }
}