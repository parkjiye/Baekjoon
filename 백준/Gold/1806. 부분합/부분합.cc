#include <iostream>

using namespace std;

int myMap[100005];

int main()
{
    int N, M;
    cin >> N >> M;

    int ans = 100005;
    int l = 0, sum = 0;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        myMap[i] = x;
        sum += x;

        while (sum >= M && l < N)
        {
            ans = min(ans, (i - l) + 1);
            sum -= myMap[l];
            l += 1;
        }
    }

    if (ans == 100005)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}