#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

bool isPrime[4000005];
vector<int> v;

int main()
{
    int N;
    cin >> N;

    for (int i = 2; i <= N; i++)
    {
        if (!isPrime[i])
        {
            for (int j = 2; j * i <= N; j++)
            {
                isPrime[j * i] = true;
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (!isPrime[i])
        {
            v.push_back(i);
        }
    }

    int right = 0;
    int sum = 0;
    int ans = 0;

    for (int i = 0; i < v.size(); i++)
    {
        while (sum < N && right < v.size())
        {
            sum += v[right];
            right += 1;
        }

        if (sum == N)
        {
            ans += 1;
        }

        sum -= v[i];
    }

    cout << ans << "\n";
}