#include <iostream>

using namespace std;

bool isPrime(long long num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    for (long long i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

long long findNextPrime(long long n)
{
    if (n <= 2)
        return 2;
    if (n % 2 == 0)
        n++;
    while (!isPrime(n))
    {
        n += 2;
    }

    return n;
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        long n;
        cin >> n;

        cout << findNextPrime(n) << "\n";
    }
}