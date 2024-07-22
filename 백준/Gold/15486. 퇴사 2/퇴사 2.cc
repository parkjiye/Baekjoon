#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<pair<int, int>> v;
int sum[1500005] = {
    0,
};

int main()
{
    FASTIO();

    int N;
    cin >> N;
    v.push_back({0, 0});

    for (int i = 0; i < N; i++)
    {
        int t, p;
        cin >> t >> p;

        v.push_back({t, p});
    }

    for (int i = 1; i <= N; i++)
    {
        sum[i] = max(sum[i - 1], sum[i]);

        if (v[i].first + i - 1 > N)
        {
            continue;
        }

        sum[i + v[i].first - 1] = max(sum[i - 1] + v[i].second, sum[i + v[i].first - 1]);
    }

    cout << sum[N] << "\n";
}