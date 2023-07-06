#include <iostream>
#include <algorithm>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct medal
{
    int idx;
    int gold;
    int silver;
    int bronze;

    medal(int idx, int gold, int silver, int bronze) : idx(idx), gold(gold), silver(silver), bronze(bronze) {}
    medal() {}
};

int main()
{
    FASTIO();
    int N, K;
    cin >> N >> K;

    vector<medal> v;
    medal cur;

    for (int i = 0; i < N; i++)
    {
        int idx, g, s, b;
        cin >> idx >> g >> s >> b;

        if (idx == K)
        {
            cur = medal(idx, g, s, b);
        }

        v.push_back(medal(idx, g, s, b));
    }

    int ans = 1;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].gold > cur.gold)
        {
            ans += 1;
        }
        else if (v[i].gold == cur.gold)
        {
            if (v[i].silver > cur.silver)
            {
                ans += 1;
            }
            else if (v[i].silver == cur.silver)
            {
                if (v[i].bronze > cur.bronze)
                {
                    ans += 1;
                }
            }
        }
    }

    cout << ans << endl;
}