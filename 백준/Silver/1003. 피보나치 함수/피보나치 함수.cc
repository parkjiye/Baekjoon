#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int zero, one;

struct p
{
    long long zero;
    long long one;
};

p make_p(long long a, long long b)
{
    p temp;
    temp.zero = a;
    temp.one = b;
    return temp;
}

vector<p> arr;

void fibonacci(int n)
{
}

int main()
{
    int test_cases;
    cin >> test_cases;

    for (int test_case = 0; test_case < test_cases; test_case++)
    {
        int num;
        cin >> num;

        memset(&arr, 0, sizeof(arr));

        arr.push_back(make_p(1, 0));
        arr.push_back(make_p(0, 1));

        for (int i = 2; i <= num; i++)
        {
            arr.push_back(make_p(arr[i - 2].zero + arr[i - 1].zero, arr[i - 2].one + arr[i - 1].one));
        }

        cout << arr[num].zero << " " << arr[num].one << endl;
    }
}