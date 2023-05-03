#include <iostream>
#include <algorithm>

using namespace std;

int increasing[1005];
int decreasing[1005];
int arr[1005];

int main()
{
    int N;
    cin >> N;

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }

    for (int i = 0; i < N; i++)
    {
        increasing[i] = 1;
        decreasing[i] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                increasing[i] = max(increasing[i], increasing[j] + 1);
            }
        }
    }

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = N - 1; j > i; j--)
        {
            if (arr[i] > arr[j])
            {
                decreasing[i] = max(decreasing[i], decreasing[j] + 1);
            }
        }

        int sum = increasing[i] + decreasing[i];

        if (sum > answer)
        {
            answer = sum;
        }
    }

    cout << answer - 1 << endl;

    return 0;
}