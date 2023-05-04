#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];
int cnt[1000];
int sum[1000];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
        cnt[i] = 1;
    }

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                cnt[i] = max(cnt[j] + 1, cnt[i]);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (cnt[i] == 1)
        {
            sum[i] = arr[i];
        }
        else
        {
            int temp = 0;

            for (int j = 0; j < i; j++)
            {
                if (cnt[j] <= cnt[i] - 1 && arr[j] < arr[i])
                {
                    if (temp < sum[j])
                    {
                        temp = sum[j];
                    }
                }
            }

            sum[i] = temp + arr[i];
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (answer < sum[i])
        {
            answer = sum[i];
        }
    }

    cout << answer << endl;
    return 0;
}