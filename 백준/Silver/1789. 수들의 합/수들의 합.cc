#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO();

    long S;
    cin >> S;

    long num = 1;
    int ans = 1;

    while (num <= S)
    {
        num += (ans + 1);
        ans += 1;
    }

    cout << ans - 1 << "\n";
}
