#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int myMap[10005];
    int sum[10005];

    memset(sum, 0, sizeof(sum));

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        myMap[i] = x;
    }

    sum[0] = myMap[0];
    sum[1] = sum[0] + myMap[1];

    for (int i = 2; i < n; i++)
    {
        sum[i] = max(sum[i - 3] + myMap[i - 1] + myMap[i], max(sum[i - 2] + myMap[i], sum[i - 1]));
    }

    cout << sum[n - 1] << endl;
}