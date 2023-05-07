#include <iostream>
#include <map>

using namespace std;

map<long long, long long> arr;

long long N;

long long fibonacci(long long num)
{
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1 || num == 2)
    {
        return 1;
    }

    if (arr.count(num) > 0)
    {
        return arr[num];
    }

    if (num % 2 == 0)
    {
        long long num1 = fibonacci(num / 2 - 1);
        long long num2 = fibonacci(num / 2);

        arr[num] = ((num1 * 2 + num2) * num2) % 1000000007;

        return arr[num];
    }

    long long num1 = fibonacci((num + 1) / 2);
    long long num2 = fibonacci((num + 1) / 2 - 1);

    arr[num] = (num1 * num1 + num2 * num2) % 1000000007;

    return arr[num];
}

int main()
{
    cin >> N;

    cout << fibonacci(N)<< endl;
}