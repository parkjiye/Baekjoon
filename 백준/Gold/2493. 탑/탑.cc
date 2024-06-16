#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct tower
{
    int h;
    int p;

    tower(int h, int p) : h(h), p(p) {}
    tower() {}

    bool const operator<(tower temp) const
    {
        return h > temp.h;
    }
};

priority_queue<tower> pq;

vector<int> v;
vector<int> t;

int main()
{
    int N;
    cin >> N;

    t.resize(N, 0);

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }

    for (int i = N - 1; i >= 0; i--)
    {
        int cur = v[i];

        while (!pq.empty())
        {
            if (pq.top().h <= cur)
            {
                tower c = pq.top();
                pq.pop();
                t[c.p] = i + 1;
            }
            else
            {
                break;
            }
        }

        if (i == 0)
        {
            break;
        }

        if (cur <= v[i - 1])
        {
            t[i] = i;
        }
        else
        {
            pq.push(tower(v[i], i));
        }

        // for (int i = 0; i < N; i++)
        // {
        //     cout << t[i] << " ";
        // }
        // cout << "\n";
    }

    for (int i = 0; i < N; i++)
    {
        cout << t[i] << " ";
    }
    cout << "\n";
}