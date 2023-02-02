#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int arr[15000];

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    sort(arr, arr + N);

    int left = 0;
    int right = N - 1;

    int cnt = 0;

    while (left != right && arr[left] <= arr[right])
    {
        if (arr[left] + arr[right] < M)
        {
            left++;
        }
        else if (arr[left] + arr[right] == M)
        {
            cnt += 1;
            left++;
            right--;
        }
        else
        {
            right--;
        }
    }

    cout << cnt << endl;
    return 0;
}