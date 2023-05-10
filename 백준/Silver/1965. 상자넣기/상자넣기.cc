#include <iostream>
#include <algorithm>

using namespace std;

int arr[1005];
int cnt[1005];

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

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        if (cnt[i] > answer)
        {
            answer = cnt[i];
        }
    }

    cout << answer << endl;
    return 0;
}