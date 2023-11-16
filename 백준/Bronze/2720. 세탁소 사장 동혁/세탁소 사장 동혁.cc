#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO();
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int x;
        cin >> x;

        cout << x / 25 << " ";
        x %= 25;
        cout << x / 10 << " ";
        x %= 10;
        cout << x / 5 << " ";
        x %= 5;
        cout << x << endl;
    }
}