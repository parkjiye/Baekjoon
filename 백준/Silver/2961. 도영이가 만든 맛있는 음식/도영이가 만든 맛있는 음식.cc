#include <iostream>
#include <cmath>
#include <vector>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<pair<int, int>> v;
int N;

int main()
{
    FASTIO();

    cin >> N;
    int ans = 1000000000;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        v.push_back({x, y});
    }

    for (int i = 1; i < pow(2, N); i++)
    {
        int sour = 1;
        int bitter = 0;

        for (int j = 0; j < N; j++)
        {
            if (i & 1 << j)
            {
                sour *= v[j].first;
                bitter += v[j].second;
            }
        }

        if (abs(sour - bitter) < ans)
        {
            ans = abs(sour - bitter);
        }
    }

    cout << ans << "\n";
}