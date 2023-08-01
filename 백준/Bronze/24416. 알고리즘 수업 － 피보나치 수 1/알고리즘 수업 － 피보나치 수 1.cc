#include <iostream>
#include <vector>

using namespace std;

vector<long long> v(50, -1);
int ans;

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        ans += 1;
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main()
{
    int N;
    cin >> N;
    ans = 0;

    fib(N);

    cout << ans << " " << N - 2 << endl;
}