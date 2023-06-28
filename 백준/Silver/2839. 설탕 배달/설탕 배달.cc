#include <iostream>
#include <string.h>

using namespace std;

int myMap[5005];

int main()
{
    int N;
    cin >> N;

    memset(myMap, 0, sizeof(myMap));

    myMap[1] = 10000;
    myMap[2] = 10000;
    myMap[3] = 1;
    myMap[4] = 10000;
    myMap[5] = 1;

    for (int i = 6; i <= N; i++)
    {
        myMap[i] = min(myMap[i - 3] + 1, myMap[i - 5] + 1);
    }

    if (myMap[N] >= 10000)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << myMap[N] << endl;
    }
}