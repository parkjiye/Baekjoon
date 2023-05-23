#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    bool check[30];
    memset(check, 0, sizeof(check));

    for (int i = 0; i < 28; i++)
    {
        int x;
        cin >> x;
        check[x - 1] = true;
    }

    for (int i = 0; i < 30; i++)
    {
        if (!check[i])
        {
            cout << i + 1 << endl;
        }
    }

    return 0;
}