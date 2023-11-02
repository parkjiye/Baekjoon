#include <iostream>
#include <queue>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

string S, T;

int main()
{
    FASTIO();
    cin >> S >> T;

    while (S != T)
    {
        if (T.size() == 0)
        {
            cout << 0 << "\n";
            return 0;
        }
        if (T[T.size() - 1] == 'A')
        {
            T.erase(T.end() - 1);
        }
        else if (T[T.size() - 1] == 'B')
        {
            T.erase(T.end() - 1);
            reverse(T.begin(), T.end());
        }
    }

    cout << 1 << "\n";
}