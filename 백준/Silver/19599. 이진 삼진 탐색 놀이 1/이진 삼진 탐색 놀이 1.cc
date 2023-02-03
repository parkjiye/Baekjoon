#include <iostream>

using namespace std;

int bdata[500001] = {0};

void binary_search(int left, int right, int cnt)
{

    if (left > right)
        return;
    int mid = (left + right) / 2;

    bdata[mid] += cnt++;
    binary_search(left, mid - 1, cnt);
    binary_search(mid + 1, right, cnt);
}

void ternary_search(int left, int right, int cnt)
{
    if (left > right)
        return;

    if (left == right)
    {
        bdata[left] -= cnt;
        return;
    }

    int left_third = left + (right - left) / 3;
    int right_third = right - (right - left) / 3;

    bdata[left_third] -= cnt++;
    bdata[right_third] -= cnt++;

    ternary_search(left, left_third - 1, cnt);
    ternary_search(left_third + 1, right_third - 1, cnt);
    ternary_search(right_third + 1, right, cnt);
}

int main()
{
    int N;
    cin >> N;

    binary_search(0, N - 1, 0);
    ternary_search(0, N - 1, 0);

    int a, b, c;
    a = b = c = 0;
    for (int i = 0; i < N; i++)
    {
        if (bdata[i] < 0)
            ++a;
        else if (bdata[i] == 0)
            ++b;
        else if (bdata[i] > 0)
            ++c;
    }

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}