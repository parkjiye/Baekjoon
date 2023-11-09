#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int change = 1000 - N;

    int ans = 0;

    ans += change / 500;
    change %= 500;
    ans += change / 100;
    change %= 100;
    ans += change / 50;
    change %= 50;
    ans += change / 10;
    change %= 10;
    ans += change / 5;
    change %= 5;
    ans += change / 1;

    cout << ans << "\n";
}