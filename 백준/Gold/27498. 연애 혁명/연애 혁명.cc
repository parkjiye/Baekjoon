#include <iostream>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;

struct love
{
    int from;
    int to;
    int quantity;
    bool possible;

    bool operator<(const love temp) const
    {
        if (possible == temp.possible)
        {
            return quantity < temp.quantity;
        }
        return possible < temp.possible;
    }

    love() {}
    love(int from, int to, int quantity, bool possible) : from(from), to(to), quantity(quantity), possible(possible) {}
};

int lovers[10005];

int findParents(int idx)
{
    if (idx == lovers[idx])
    {
        return idx;
    }
    else
    {
        return lovers[idx] = findParents(lovers[idx]);
    }
}

int main()
{
    FASTIO();
    cin >> N >> M;

    priority_queue<love> pq;

    for (int i = 0; i < M; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        pq.push(love(a, b, c, d));
    }

    for (int i = 1; i <= N; i++)
    {
        lovers[i] = i;
    }

    int giveup = 0;

    while (!pq.empty())
    {
        love cur = pq.top();
        pq.pop();

        int a = findParents(cur.from);
        int b = findParents(cur.to);

        if (a == b)
        {
            giveup += cur.quantity;
            continue;
        }
        else if (a < b)
        {
            lovers[b] = a;
        }
        else
        {
            lovers[a] = b;
        }
    }

    cout << giveup << endl;
}