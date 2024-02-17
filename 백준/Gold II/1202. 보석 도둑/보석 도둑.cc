#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, K;

struct Jewel
{
    int weight;
    int cost;

    Jewel() {}
    Jewel(int weight, int cost) : weight(weight), cost(cost) {}

    bool operator<(const Jewel temp) const
    {
        if (temp.cost == cost)
        {
            return temp.weight < weight;
        }
        return temp.cost > cost;
    }
};

priority_queue<Jewel> jewels;
multimap<int, long> bags;

int b[300005];

int main()
{
    FASTIO();
    cin >> N >> K;
    memset(b, 0, sizeof(b));

    for (int i = 0; i < N; i++)
    {
        int m, v;
        cin >> m >> v;

        jewels.push(Jewel(m, v));
    }

    for (int i = 0; i < K; i++)
    {
        int c;
        cin >> c;

        bags.insert({c, 0});
    }

    long long answer = 0;

    while (!jewels.empty())
    {
        Jewel cur = jewels.top();
        jewels.pop();

        bool tmp = false;

        auto et = bags.lower_bound(cur.weight);

        if (et == bags.end())
        {
            continue;
        }

        for (auto it = et; it != bags.end(); it++)
        {
            // cout << (*it) << "\n";
            if (it->second == 0)
            {
                it->second = cur.cost;
                answer += it->second;
                bags.erase(it);
                break;
            }
        }
    }

    cout << answer << "\n";
}