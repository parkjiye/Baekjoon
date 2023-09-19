#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int V, E;

struct p
{
    int x;
    int y;
    int s;

    p(int x, int y, int s) : x(x), y(y), s(s) {}
    p() {}

    bool operator<(const p temp) const
    {
        if (s > temp.s)
        {
            return true;
        }
        return false;
    }
};

priority_queue<p> pq;

int Cycle[10005];

int findParents(int idx)
{
    if (idx == Cycle[idx])
    {
        return idx;
    }
    else
    {
        return Cycle[idx] = findParents(Cycle[idx]);
    }
}

int main()
{
    FASTIO();
    cin >> V >> E;

    int total = 0;

    for (int i = 1; i <= V; i++)
    {
        Cycle[i] = i;
    }

    for (int i = 0; i < E; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;

        pq.push(p(a, b, d));
    }

    while (!pq.empty())
    {
        p cur = pq.top();
        pq.pop();

        int a = findParents(cur.x);
        int b = findParents(cur.y);

        if (a == b)
        {
            continue;
        }
        else if (a < b)
        {
            Cycle[b] = a;
            total += cur.s;
        }
        else
        {
            Cycle[a] = b;
            total += cur.s;
        }
    }

    cout << total << endl;
}