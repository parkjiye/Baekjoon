#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct p
{
    int s;
    int t;

    p() {}
    p(int s, int t) : s(s), t(t) {}

    bool operator<(const p temp) const
    {
        return t < temp.t;
    }
};

int main()
{
    FASTIO();
    int N;
    cin >> N;

    priority_queue<p> pq;
    priority_queue<int> q;

    for (int i = 0; i < N; i++)
    {
        int s, t;
        cin >> s >> t;
        pq.push(p(s, t));
    }

    int ans = 0;

    while (!pq.empty())
    {
        p cur = pq.top();
        pq.pop();

        if (q.empty())
        {
            q.push(cur.s);
            ans += 1;
        }
        else
        {
            // cout << q.top() << "\n";
            if (q.top() < cur.t)
            {
                q.push(cur.s);
                ans += 1;
            }
            else
            {
                q.pop();
                q.push(cur.s);
            }
        }
    }

    cout << ans << "\n";
}
