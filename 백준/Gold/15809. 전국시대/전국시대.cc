#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int world[100005];
int soldiers[100005];

int findParents(int idx)
{
    if (world[idx] == idx)
    {
        return idx;
    }
    else
    {
        return world[idx] = findParents(world[idx]);
    }
}

int main()
{
    FASTIO();

    int N, M;
    cin >> N >> M;

    map<int, int> m;

    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;

        world[i] = i;
        soldiers[i] = x;
    }

    for (int i = 0; i < M; i++)
    {
        int o, p, q;
        cin >> o >> p >> q;

        p = findParents(p);
        q = findParents(q);

        if (o == 1)
        {
            if (p < q)
            {
                world[q] = p;
                soldiers[p] += soldiers[q];
                soldiers[q] = 0;
            }
            else
            {
                world[p] = q;
                soldiers[q] += soldiers[p];
                soldiers[p] = 0;
            }
        }
        else
        {

            if (soldiers[p] > soldiers[q])
            {
                soldiers[p] -= soldiers[q];
                soldiers[q] = 0;
                world[q] = p;
            }
            else
            {
                soldiers[q] -= soldiers[p];
                soldiers[p] = 0;
                world[p] = q;
            }
        }
    }

    vector<int> v;

    for (int i = 1; i <= N; i++)
    {
        if (soldiers[findParents(i)] == 0 || i != world[i])
            continue;
        v.push_back(soldiers[findParents(i)]);
    }

    cout << v.size() << endl;

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}