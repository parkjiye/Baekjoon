#include <iostream>

using namespace std;

char myMap[65][65];
string sen;

void divide(int N, int x, int y)
{

    char check = myMap[x][y];
    bool diff = false;

    for (int i = x; i < x + N; i++)
    {
        for (int j = y; j < y + N; j++)
        {
            if (check != myMap[i][j])
            {
                diff = true;
                break;
            }
        }
    }

    if (!diff)
    {
        sen += check;
    }
    else
    {
        sen += '(';
        divide(N / 2, x, y);
        divide(N / 2, x, y + N / 2);
        divide(N / 2, x + N / 2, y);
        divide(N / 2, x + N / 2, y + N / 2);
        sen += ')';
    }

    return;
}

int main()
{
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < num; j++)
        {
            myMap[i][j] = s[j];
        }
    }

    divide(num, 0, 0);

    cout << sen << endl;
}