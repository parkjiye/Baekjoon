#include <iostream>

using namespace std;

long long myMap[101];

int main()
{
    int test_cases;
    cin >> test_cases;

    myMap[1] = 1;
    myMap[2] = 1;
    myMap[3] = 1;
    myMap[4] = 2;
    myMap[5] = 2;

    for (int i = 6; i < 101; i++)
    {
        myMap[i] = myMap[i - 1] + myMap[i - 5];
    }

    for (int test_case = 0; test_case < test_cases; test_case++)
    {
        int num;
        cin >> num;

        cout << myMap[num] << endl;
    }
}