#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int arr[100001];

    int x;
    cin >> x;
    arr[0] = x;

    for (int i = 1; i < N; i++)
    {
        int x;
        cin >> x;

        arr[i] = arr[i - 1] + x;
    }

    for (int i = 0; i < M; i++)
    {
        int left;
        int right;
        cin >> left >> right;

        if (left - 2 == -1)
        {
            cout << arr[right - 1] << "\n";
        }
        else
        {
            cout << arr[right - 1] - arr[left - 2] << "\n";
        }
    }
}