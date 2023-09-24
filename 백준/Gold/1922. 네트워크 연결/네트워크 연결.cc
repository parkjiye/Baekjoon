#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int computers[1005];

int findParents(int idx)
{
    if (idx == computers[idx])
    {
        return idx;
    }
    else
    {
        return computers[idx] = findParents(computers[idx]);
    }
}

struct p
{
    int x;
    int y;
    int s;

    p() {}
    p(int x, int y, int s) : x(x), y(y), s(s) {}

    bool operator<(const p temp) const
    {
        return s > temp.s;
    }
};

int main()
{
    FASTIO();
    cin >> N >> M;

    priority_queue<p> pq;

    for (int i = 1; i <= N; i++)
    {
        computers[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        pq.push(p(a, b, c));
    }

    int ans = 0;

    while (!pq.empty())
    {
        p cur = pq.top();
        pq.pop();

        int x = findParents(cur.x);
        int y = findParents(cur.y);

        if (x == y)
        {
            continue;
        }
        else if (x < y)
        {
            computers[y] = x;
            ans += cur.s;
        }
        else
        {
            computers[x] = y;
            ans += cur.s;
        }
    }

    cout << ans << endl;
}
