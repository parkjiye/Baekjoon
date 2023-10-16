#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int num[100000] = {
    10001,
};

vector<int> v;
int N, K;

int main()
{
    FASTIO();
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        num[x] = 1;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= K; i++)
    {
        int max_value = 10001;

        for (int j = 0; j < N; j++)
        {
            if (i < v[j])
            {
                break;
            }

            if (i != v[j])
            {
                max_value = min(num[i - v[j]] + 1, max_value);
            }
            else
            {
                max_value = min(num[i - v[j]] + 1, min(max_value, num[i]));
            }
        }

        num[i] = max_value;
        // cout << max_value << "\n";
    }

    if (num[K] == 10001)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << num[K] << "\n";
    }
}