#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int arr[50001];

    int num;
    cin >> num;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 1;

    int after = 2;

    for (int i = 5; i <= num; i++)
    {
        int minn = 100;

        if (i == pow((after + 1), 2))
        {
            arr[i] = 1;
            after += 1;
        }
        else
        {
            for (int j = 1; j <= after; j++)
            {
                int a = i - pow(j, 2);
                minn = min(minn, arr[a]);
            }
            arr[i] = minn + 1;
        }

        // cout << arr[i] << endl;
    }

    cout << arr[num] << endl;
}