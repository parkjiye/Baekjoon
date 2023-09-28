#include <iostream>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int P, G;

int gate[100005];

int findParents(int idx)
{
    if (idx == gate[idx])
    {
        return idx;
    }
    else
    {
        return gate[idx] = findParents(gate[idx]);
    }
}

int main()
{
    FASTIO();
    cin >> G >> P;

    int planes = 0;
    bool occupied = false;

    for (int i = 1; i <= G; i++)
    {
        gate[i] = i;
    }

    for (int i = 1; i <= P; i++)
    {
        int x;
        cin >> x;

        if (occupied)
        {
            continue;
        }

        int cur = findParents(x);

        if (cur != 0)
        {
            gate[cur] -= 1;
            planes += 1;
        }
        else if (cur == 0)
        {
            occupied = true;
        }
    }

    cout << planes << endl;
}