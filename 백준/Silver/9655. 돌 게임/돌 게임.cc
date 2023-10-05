#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int t = N % 3;     // 3개씩 가져가고 남은 돌
    int k = N / 3 % 2; // 3개씩 가져간 마지막 사람

    if (k == 1) // 상근이가 3개의 마지막
    {
        if (t == 0 || t == 2)
        {
            cout << "SK" << endl;
        }
        else
        {
            cout << "CY" << endl;
        }
    }
    else
    {
        if (t == 0 || t == 2)
        {
            cout << "CY" << endl;
        }
        else
        {
            cout << "SK" << endl;
        }
    }
}