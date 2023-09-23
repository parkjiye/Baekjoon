#include <iostream>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;

int house[100005];

struct road
{
    int x;
    int y;
    int s;

    road(int x, int y, int s) : x(x), y(y), s(s) {}
    road() {}

    bool operator<(const road temp) const
    {
        if (s > temp.s)
        {
            return true;
        }
        return false;
    }
};

int findParents(int idx)
{
    if (idx == house[idx])
    {
        return idx;
    }
    else
    {
        return house[idx] = findParents(house[idx]);
    }
}

int main()
{
    FASTIO();

    cin >> N >> M;
    priority_queue<road> pq;

    for (int i = 1; i <= N; i++)
    {
        house[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        pq.push(road(a, b, c));
    }

    int total = 0;
    int last = 0;

    while (!pq.empty())
    {
        road cur = pq.top();
        pq.pop();

        int x = findParents(cur.x);
        int y = findParents(cur.y);

        if (x == y)
        {
            continue;
        }
        else if (x < y)
        {
            house[y] = x;
            total += cur.s;
            last = cur.s;
        }
        else
        {
            house[x] = y;
            total += cur.s;
            last = cur.s;
        }
    }

    cout << total - last << "\n";
}