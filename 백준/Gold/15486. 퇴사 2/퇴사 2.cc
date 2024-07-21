#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
vector<pair<int, int>> v;
vector<int> dp;

int main()
{
    FASTIO();
    cin >> N;

    dp.resize(N + 1, 0);
    v.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        int d, t;
        cin >> d >> t;
        v[i] = {d, t};
    }

    for (int i = 1; i <= N; i++)
    {
        // 이전 단계에서의 최대 수익을 유지
        dp[i] = max(dp[i], dp[i - 1]);

        int end_day = i + v[i].first - 1;
        if (end_day <= N)
        {
            // 현재 작업을 수행하는 경우와 하지 않는 경우 중 최대값 선택
            dp[end_day] = max(dp[end_day], dp[i - 1] + v[i].second);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";

    return 0;
}
