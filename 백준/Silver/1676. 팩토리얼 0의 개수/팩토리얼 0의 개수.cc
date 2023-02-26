#include <iostream>

using namespace std;

int two(int x)
{
    int cnt = 0;

    while (x % 2 == 0)
    {
        cnt += 1;
        x = x / 2;
    }

    return cnt;
}

int five(int x)
{
    int cnt = 0;

    while (x % 5 == 0)
    {
        cnt += 1;
        x = x / 5;
    }

    return cnt;
}

int main()
{
    int n;
    cin >> n;

    pair<int, int> p = {0, 0};

    for (int i = 1; i <= n; i++)
    {
        // cout << p.first << " " << p.second << endl;
        p = pair<int, int>(p.first + two(i), p.second + five(i));
    }

    cout << p.second << endl;
    return 0;
}