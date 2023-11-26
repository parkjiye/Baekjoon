#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
vector<int> v;

int weights[1005] = {
    0,
};
int acc[1005] = {
    0,
};

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= N; i++)
    {
        weights[i] = v[i - 1];
    }

    int start = 0;
    int end = 0;

    bool found = false;

    for (int i = 1; i <= N; i++)
    {
        if (weights[i] <= acc[i - 1] + 1)
        {
            acc[i] = acc[i - 1] + weights[i];
        }
        else
        {
            found = true;
            cout << acc[i - 1] + 1 << "\n";
            return 0;
        }
    }

    if (!found)
    {
        cout << acc[N] + 1 << "\n";
    }
    return 0;
}