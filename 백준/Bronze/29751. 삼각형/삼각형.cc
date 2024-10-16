#include <iostream>

using namespace std;

int main()
{
    double W, H;
    cin >> W >> H;

    double ans = W * H / 2;

    cout << fixed;
    cout.precision(1);

    cout << ans << "\n";
}