#include <iostream>
#include <math.h>

using namespace std;

int A, B, C;

long long recursion(int start)
{
    if (start == 0)
        return 1;
    long long temp = recursion(start / 2);
    temp = temp * temp % C;
    if (start % 2 == 0)
        return temp;
    else
        return A * temp % C;
}

int main()
{
    cin >> A >> B >> C;

    long long answer = 1;

    cout << recursion(B) << endl;

    return 0;
}