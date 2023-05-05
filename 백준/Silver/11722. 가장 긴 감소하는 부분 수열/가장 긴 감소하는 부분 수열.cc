#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];
int cnt[1000];

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
            if (arr[i] < arr[j])
            {
                cnt[i] = max(cnt[j] + 1, cnt[i]);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (answer < cnt[i])
        {
            answer = cnt[i];
        }
    }

    cout << answer << endl;
    return 0;
}