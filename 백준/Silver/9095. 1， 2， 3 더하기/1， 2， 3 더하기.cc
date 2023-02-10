#include <iostream>

using namespace std;

int main()
{
    int test_cases;
    cin >> test_cases;

    int arr[11];

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for (int i = 0; i < test_cases; i++)
    {
        int N;
        cin >> N;

        for (int j = 4; j <= N; j++)
        {
            arr[j] = arr[j - 3] + arr[j - 2] + arr[j - 1];
        }

        cout << arr[N] << "\n";
    }
}