#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
bool sex[1005];
long love[1005];

struct univ
{
    int from;
    int where;
    int dist;

    univ(int from, int where, int dist) : from(from), where(where), dist(dist) {}
    univ() {}

    bool operator<(const univ temp) const
    {
        return dist > temp.dist;
    }
};

int findParents(int idx)
{
    if (idx == love[idx])
    {
        return idx;
    }
    else
    {
        return love[idx] = findParents(love[idx]);
    }
}

int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        char c;
        cin >> c;

        if (c == 'M')
        {
            sex[i] = 0;
        }
        else
        {
            sex[i] = 1;
        }

        love[i] = i;
    }

    priority_queue<univ> pq;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (sex[a] != sex[b])
        {
            pq.push(univ(a, b, c));
        }
    }

    long total = 0;
    int cnt = 0;

    while (!pq.empty())
    {
        univ cur = pq.top();
        pq.pop();

        int a = findParents(cur.from);
        int b = findParents(cur.where);

        if (a == b)
        {
            continue;
        }
        else if (a < b)
        {
            love[b] = a;
            total += cur.dist;
            cnt += 1;
        }
        else
        {
            love[a] = b;
            total += cur.dist;
            cnt += 1;
        }
    }

    if (cnt != N - 1)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << total << endl;
}