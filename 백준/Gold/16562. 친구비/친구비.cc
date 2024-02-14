#include <iostream>
#include <map>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct Friend
{
    int idx;
    int cost;

    Friend() {}
    Friend(int idx, int cost) : idx(idx), cost(cost) {}

    bool operator<(Friend temp)
    {
        return cost > temp.cost;
    }
};

int N, M, k;
Friend f[10005];
int union_set[10005];
map<int, int> m;

int find_Parent(int idx)
{
    if (idx == union_set[idx])
    {
        return idx;
    }
    else
    {
        return union_set[idx] = find_Parent(union_set[idx]);
    }
}

int main()
{
    FASTIO();
    cin >> N >> M >> k;

    for (int i = 0; i < N; i++)
    {
        union_set[i] = i;
    }

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        f[i] = Friend(i, x);
    }

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        int p_x = find_Parent(x - 1);
        int p_y = find_Parent(y - 1);

        if (p_x < p_y)
        {
            union_set[p_y] = p_x;
        }
        else if (p_x > p_y)
        {
            union_set[p_x] = p_y;
        }
    }

    for (int i = 0; i < N; i++)
    {
        int p = find_Parent(i);

        if (m.find(p) != m.end())
        {
            if (m[p] > f[i].cost)
            {
                m[p] = f[i].cost;
            }
        }
        else if (m.find(p) == m.end())
        {
            m.insert({p, f[i].cost});
        }
    }

    int sum = 0;

    for (auto it = m.begin(); it != m.end(); it++)
    {
        sum += it->second;
    }

    if (sum > k)
    {
        cout << "Oh no"
             << "\n";
    }
    else
    {
        cout << sum << "\n";
    }
}