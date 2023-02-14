#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;

    int myMap[1001];

    myMap[1] = 1;
    myMap[2] = 2;

    for (int i = 3; i <= 1000; i++)
    {
        myMap[i] = (myMap[i - 2] + myMap[i - 1]) % 10007;
    }

    cout << myMap[num] << endl;
}