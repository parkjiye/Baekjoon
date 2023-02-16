#include <iostream>

using namespace std;

long long myMap[1000001];

int main()
{
    int num;
    cin >> num;

    myMap[2] = 1;
    myMap[3] = 1;

    for (int i = 4; i <= num; i++)
    {
        if (i % 2 == 0 && i % 3 == 0)
        {
            myMap[i] = min(myMap[i / 3] + 1, myMap[i / 2] + 1);
        }
        else if (i % 3 == 0 && i % 2 != 0)
        {
            myMap[i] = min(myMap[i / 3] + 1, myMap[i - 1] + 1);
        }
        else if (i % 3 != 0 && i % 2 == 0)
        {
            myMap[i] = min(myMap[i / 2] + 1, myMap[i - 1] + 1);
        }
        else
        {
            myMap[i] = myMap[i - 1] + 1;
        }
    }

    cout << myMap[num] << endl;
}