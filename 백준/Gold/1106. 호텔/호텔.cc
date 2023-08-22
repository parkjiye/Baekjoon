#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_INT 10000000

using namespace std;

int C, N;

int cost[1300] = {
    0,
};

vector<int> v;

int main()
{
    cin >> C >> N;

    for (int i = 0; i < N; i++)
    {
        int c, x;
        cin >> c >> x;

        if (cost[x] != 0)
        {
            cost[x] = min(cost[x], c);
        }
        else
        {
            cost[x] = c;
        }
    }

    for (int i = 0; i <= 1200; i++)
    {
        if (cost[i] != 0)
        {
            v.push_back(i);
        }
        else
        {
            cost[i] = MAX_INT;
        }
    }

    for (int i = 1; i <= 1200; i++)
    {

        for (int j = 0; j < v.size(); j++)
        {
            if (i < v[j])
            {
                continue;
            }

            int cur = v[j];

            cost[i] = min(cost[i], cost[i - cur] + cost[cur]);
        }
    }

    int ans = MAX_INT;

    for (int i = C; i <= 1200; i++)
    {
        if (cost[i] < ans && cost[i] != 0)
        {
            ans = cost[i];
        }
    }

    cout << ans << endl;
}