#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO();
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < N - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < N - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}