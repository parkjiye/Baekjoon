#include <iostream>
#include <vector>

using namespace std;

vector<long long> v(100, -1);

long long fibo(int n)
{
    if (n < 2)
    {
        return n;
    }

    if (v[n] != -1)
    {
        return v[n];
    }

    v[n] = fibo(n - 2) + fibo(n - 1);

    return v[n];
}

int main()
{
    int N;
    cin >> N;

    cout << fibo(N) << endl;
}