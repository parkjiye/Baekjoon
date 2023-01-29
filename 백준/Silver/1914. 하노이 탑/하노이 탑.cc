#include <iostream>
#include <math.h>

using namespace std;

void hanoi(int n, int from, int to, int by)
{
    if (n == 1)
    {
        cout << from << " " << to << "\n";
        return;
    }
    hanoi(n - 1, from, by, to);
    cout << from << " " << to << "\n";
    hanoi(n - 1, by, to, from);
}

int main()
{
    int N;
    cin >> N;

    string a = to_string(pow(2, N));

    // cout<<a<<endl;

    int x = a.find('.');
    a = a.substr(0, x);
    a[a.length() - 1] -= 1;

    cout << a << endl;

    if (N <= 20)
        hanoi(N, 1, 3, 2);
}
