#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

int main()
{
    cin >> N;

    int cost[20] = {0};
    int day[20] = {0};
    int ans[20] = {0};

    for (int i = 1; i <= N; i++)
    {
        int x, y;
        cin >> x >> y;

        day[i] = x;
        cost[i] = y;
    }

    for (int i = N; i > 0; i--)
    {
        int deadline = day[i] + i;
        if (deadline > N + 1)
        {
            ans[i] = ans[i + 1];
        }
        else
        {
            ans[i] = max(ans[i + 1], cost[i] + ans[deadline]);
        }
    }

    cout << ans[1] << endl;

    return 0;
}