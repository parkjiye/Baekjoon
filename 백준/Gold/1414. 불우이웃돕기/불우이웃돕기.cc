#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

struct p
{
    int x;
    int y;
    int l;

    p() {}
    p(int x, int y, int l) : x(x), y(y), l(l) {}

    bool operator<(const p temp) const
    {
        return l > temp.l;
    }
};

priority_queue<p> pq;

int computers[55];

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

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++)
        {
            char c = s[j];

            if (c != '0')
            {
                if (c > 96)
                {
                    pq.push(p(i + 1, j + 1, (int)c - 96));
                }
                else
                {
                    pq.push(p(i + 1, j + 1, (int)c - 38));
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        computers[i] = i;
    }

    int ans = 0;

    while (!pq.empty())
    {
        p cur = pq.top();
        pq.pop();

        int a = findParents(cur.x);
        int b = findParents(cur.y);

        if (a == b)
        {
            ans += cur.l;
        }
        else if (a < b)
        {
            computers[b] = a;
        }
        else
        {
            computers[a] = b;
        }
    }

    for (int i = 1; i < N; i++)
    {
        if (findParents(i) != findParents(i + 1))
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
}