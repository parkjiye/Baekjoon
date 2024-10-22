#include <iostream>
#include <map>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct p
{
    int score;
    int idx;

    p() {}
    p(int score, int idx) : score(score), idx(idx) {}

    bool const operator<(p temp) const
    {
        if (score == temp.score)
        {
            return idx > temp.idx;
        }
        return score < temp.score;
    }
};

int main()
{
    FASTIO();

    while (1)
    {
        int N, M;
        cin >> N >> M;

        if (N == 0 && M == 0)
        {
            break;
        }

        map<int, int> m;
        priority_queue<p> pq;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                int x;
                cin >> x;

                if (m.find(x) == m.end())
                {
                    m.insert({x, 1});
                }
                else
                {
                    m[x] += 1;
                }
            }
        }

        for (auto it = m.begin(); it != m.end(); it++)
        {
            pq.push(p(it->second, it->first));
        }

        pq.pop();

        p ans = pq.top();

        while (!pq.empty())
        {
            cout << ans.idx << " ";
            pq.pop();

            if (pq.top().score == ans.score)
            {
                ans = pq.top();
            }
            else
            {
                break;
            }
        }
        cout << "\n";
    }
}