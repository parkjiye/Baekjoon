#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int T;

int main()
{
    FASTIO();
    cin >> T;

    if (T % 10 != 0)
    {
        cout << -1 << "\n";
        return 0;
    }

    int a = 0;
    int b = 0;
    int c = 0;

    a += T / 300;
    T %= 300;
    b += T / 60;
    T %= 60;
    c += T / 10;

    cout << a << " " << b << " " << c << "\n";
}