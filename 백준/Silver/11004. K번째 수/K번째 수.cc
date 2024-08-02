#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<long long> v;

int main()
{
    FASTIO();
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        long long x;
        cin >> x;

        v.push_back(x);
    }

    sort(v.begin(), v.end());

    cout << v[K - 1] << "\n";
}