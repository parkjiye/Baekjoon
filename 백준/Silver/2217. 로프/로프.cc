#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO();
    int N;
    cin >> N;

    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int ans = v[N - 1];

    for (int i = 0; i < N; i++)
    {
        if (v[i] * (N - i) > ans)
        {
            ans = v[i] * (N - i);
        }
    }

    cout << ans << "\n";
}