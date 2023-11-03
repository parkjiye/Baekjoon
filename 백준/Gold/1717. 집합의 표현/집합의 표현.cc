#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n, m;
int parents[1000005];

int findParents(int idx)
{
    if (idx == parents[idx])
    {
        return idx;
    }
    else
    {
        return parents[idx] = findParents(parents[idx]);
    }
}

int main()
{
    FASTIO();
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        parents[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int x, a, b;
        cin >> x >> a >> b;

        if (x == 0)
        {
            a = findParents(a);
            b = findParents(b);

            if (a < b)
            {
                parents[b] = a;
            }
            else
            {
                parents[a] = b;
            }
        }
        else
        {
            a = findParents(a);
            b = findParents(b);

            if (a == b)
            {
                cout << "yes" << "\n";
            }
            else
            {
                cout << "no" << "\n";
            }
        }
    }
}