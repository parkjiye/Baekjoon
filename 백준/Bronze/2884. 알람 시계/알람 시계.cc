#include <iostream>

using namespace std;

int main()
{
    int H, M;
    cin >> H >> M;

    if (M >= 45)
    {
        cout << H << " " << M - 45 << "\n";
    }
    else
    {
        M = 60 - (45 - M);
        H -= 1;

        if (H == -1)
        {
            H = 23;
        }
        cout << H << " " << M << "\n";
    }
}