#include <iostream>

using namespace std;

long long int sum[10005];

int main()
{
    long long int N, M;
    long long int ans = 0;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        long long int x;
        cin >> x;

        if (i == 0)
        {
            sum[i] = x;
        }
        else
        {
            sum[i] = sum[i - 1] + x;
        }

        if (sum[i] == M)
        {
            ans += 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (sum[j] - sum[i] == M)
            {
                ans += 1;
            }
        }
    }

    cout << ans << endl;
}