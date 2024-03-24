#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, K;

struct multitap
{
    int idx;
    int left;
    int nxt;

    multitap() {}
    multitap(int idx, int left, int nxt) : idx(idx), left(left), nxt(nxt) {}

    bool const operator<(multitap temp) const
    {
        return nxt > temp.nxt;
    }
};

map<int, multitap> t;
map<int, deque<int>> m;
vector<int> v;

int main()
{
    FASTIO();
    cin >> N >> K;

    int answer = 0;

    for (int i = 1; i <= K; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);

        if (m.find(x) == m.end())
        {
            deque<int> dq;
            dq.push_back(i);
            m.insert({x, dq});
        }
        else
        {
            m[x].push_back(i);
        }
    }

    // for (auto it = m.begin(); it != m.end(); it++)
    // {
    //     cout << it->first << " " << it->second.size() << "\n";
    // }

    for (int i = 1; i <= K; i++)
    {
        // cout << i << "\n";
        int cur = v[i - 1];
        // 다 차지 않았다면
        if (t.size() < N)
        {
            // 꼽혀 있다면
            if (t.find(cur) != t.end())
            {
                m[cur].pop_front();

                if (m[cur].size())
                {
                    int left = m[cur].size();
                    int nxt = m[cur].front();
                    t[cur] = multitap(cur, left, nxt);
                }
                else
                {
                    t[cur] = multitap(cur, 200, 200);
                }
            }
            else
            {
                m[cur].pop_front();

                if (m[cur].size())
                {
                    int left = m[cur].size();
                    int nxt = m[cur].front();
                    t.insert({cur, multitap(cur, left, nxt)});
                }
                else
                {
                    t.insert({cur, multitap(cur, 200, 200)});
                }
            }
        }
        else
        {
            // 꼽혀 있다면
            if (t.find(cur) != t.end())
            {
                m[cur].pop_front();

                if (m[cur].size())
                {
                    int left = m[cur].size();
                    int nxt = m[cur].front();
                    t[cur] = multitap(cur, left, nxt);
                }
                else
                {
                    t[cur] = multitap(cur, 200, 200);
                }
            }
            // 누군가를 빼야 한다면
            else
            {
                vector<multitap> v;

                for (auto it = t.begin(); it != t.end(); it++)
                {
                    v.push_back(it->second);
                }

                sort(v.begin(), v.end());

                multitap rm = v[0];
                t.erase(rm.idx);

                // cout << "remove " << rm.idx << "\n";
                answer += 1;

                m[cur].pop_front();
                if (m[cur].size())
                {
                    int left = m[cur].size();
                    int nxt = m[cur].front();
                    t.insert({cur, multitap(cur, left, nxt)});
                }
                else
                {
                    t.insert({cur, multitap(cur, 200, 200)});
                }
            }
        }

        // for (auto it = t.begin(); it != t.end(); it++)
        // {
        //     cout << it->first << " " << it->second.left << " " << it->second.nxt << "\n";
        // }
    }

    cout << answer << "\n";
}