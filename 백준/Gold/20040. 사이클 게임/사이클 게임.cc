#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int dots[500005];

int findParents(int idx)
{
    if (idx == dots[idx])
    {
        return idx;
    }
    else
    {
        return dots[idx] = findParents(dots[idx]);
    }
}

int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        dots[i] = i;
    }

    bool find = false;

    for (long i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        if (!find)
        {
            a = findParents(a);
            b = findParents(b);

            if (a == b)
            {
                cout << i + 1 << endl;
                find = true;
                continue;
            }

            if (a < b)
            {
                dots[b] = a;
            }
            else
            {
                dots[a] = b;
            }
        }
    }

    if (!find)
    {
        cout << 0 << endl;
    }
}