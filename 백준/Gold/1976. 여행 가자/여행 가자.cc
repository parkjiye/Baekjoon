#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int city[205];

int findParents(int idx)
{
    if (idx == city[idx])
    {
        return idx;
    }
    else
    {
        return city[idx] = findParents(city[idx]);
    }
}

int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        city[i] = i;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int x;
            cin >> x;

            if (x == 1)
            {
                int a, b;
                a = findParents(i);
                b = findParents(j);

                if (a < b)
                {
                    city[b] = a;
                }
                else
                {
                    city[a] = b;
                }
            }
        }
    }

    int f;
    cin >> f;

    f = findParents(f);

    for (int i = 0; i < M - 1; i++)
    {
        int x;
        cin >> x;

        if (findParents(x) != f)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}