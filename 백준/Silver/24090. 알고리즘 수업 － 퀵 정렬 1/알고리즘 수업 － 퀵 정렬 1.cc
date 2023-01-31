#include <iostream>
#include <algorithm>
using namespace std;

int N;
int K;

int a, b;

int cnt = 0;

int partition(int data[], int left, int right)
{
    int pivot = data[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++)
    {
        if (data[j] <= pivot)
        {
            swap(data[++i], data[j]);
            cnt += 1;
            if (cnt == K)
            {
                a = data[i];
                b = data[j];
            }
        }
    }

    if (i + 1 != right)
    {
        swap(data[i + 1], data[right]);
        cnt += 1;
        if (cnt == K)
        {
            a = data[i + 1];
            b = data[right];
        }
    }

    return i + 1;
}

void quick_sort(int data[], int left, int right)
{
    if (left < right)
    {
        int p = partition(data, left, right);
        quick_sort(data, left, p - 1);
        quick_sort(data, p + 1, right);
    }
}

int main()
{
    cin >> N >> K;

    int data[10000];

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        data[i] = num;
    }

    quick_sort(data, 0, N - 1);

    if (K > cnt)
    {
        cout << -1 << endl;
        return 0;
    }

    if (a < b)
    {
        cout << a << " " << b << endl;
        return 0;
    }
    else
    {
        cout << b << " " << a << endl;
        return 0;
    }
}