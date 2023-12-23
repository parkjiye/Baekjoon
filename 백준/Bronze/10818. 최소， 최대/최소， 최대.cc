#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

int main()
{
    FASTIO();
    cin >> N;

    int s = 1000005;
    int b = -1000005;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        if (x > b)
        {
            b = x;
        }

        if (x < s)
        {
            s = x;
        }
    }

    cout << s << " " << b << "\n";
}