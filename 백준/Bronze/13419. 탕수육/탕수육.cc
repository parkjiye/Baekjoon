#include <iostream>
#include <string.h>

using namespace std;

char arr[30];
char a[30];
char b[30];

int main()
{
    int n, ja = 0, jb = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr;
        int len = strlen(arr);
        if (len % 2 == 0)
        {
            for (int k = 0; k < len; k++)
                k % 2 == 0 ? a[ja++] = arr[k] : b[jb++] = arr[k];
        }
        else
        {
            for (int k = 0; k < len; k++)
                k % 2 == 0 ? a[ja++] = arr[k] : b[jb++] = arr[k];
            for (int k = 0; k < len; k++)
                k % 2 == 0 ? b[jb++] = arr[k] : a[ja++] = arr[k];
        }
        cout << a << "\n"
             << b << "\n";

        for (int k = 0; k < len; k++)
        {
            a[k] = 0;
            b[k] = 0;
        }
        ja = 0;
        jb = 0;
    }
    return 0;
}
