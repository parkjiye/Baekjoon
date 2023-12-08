#include <iostream>

using namespace std;

int main()
{
    int L, P, V;
    int cnt = 1;

    while (1)
    {
        cin >> L >> P >> V;

        if (!L && !P && !V)
        {
            return 0;
        }

        int sum = V / P * L;

        if (L > V % P)
        {
            sum += (V % P);
        }
        else
        {
            sum += L;
        }

        cout << "Case " << cnt << ": " << sum << "\n";
        cnt += 1;
    }
}