#include <iostream>

using namespace std;

int main()
{
    int myMap[1000];

    int num;
    cin >> num;

    myMap[1] = 1;
    myMap[2] = 3;

    for (int i = 3; i <= num; i++)
    {
        myMap[i] = (myMap[i - 2] * 2 + myMap[i - 1]) % 10007;
    }

    cout << myMap[num] << endl;
}