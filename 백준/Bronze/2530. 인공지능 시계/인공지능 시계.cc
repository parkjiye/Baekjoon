#include <iostream>

using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int sec, min, hour;

    hour = D / 3600;
    min = D % 3600 / 60;
    sec = D % 60;

    if (C + sec >= 60)
    {
        B += 1;
    }
    C = (C + sec) % 60;

    if (B + min >= 60)
    {
        A += 1;
    }
    B = (B + min) % 60;
    A = (A + hour) % 24;

    cout << A << " " << B << " " << C << "\n";
}