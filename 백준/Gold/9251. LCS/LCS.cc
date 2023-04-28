#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int myMap[1005][1005];

int main()
{
    string sen1, sen2;
    cin >> sen1 >> sen2;

    memset(myMap, 0, sizeof(myMap));

    for (int i = 1; i <= sen2.length(); i++)
    {
        for (int j = 1; j <= sen1.length(); j++)
        {
            if (sen2[i - 1] == sen1[j - 1])
            {
                myMap[i][j] = myMap[i - 1][j - 1] + 1;
            }
            else
            {
                myMap[i][j] = max(myMap[i][j - 1], myMap[i - 1][j]);
            }
        }
    }

    int idx = 1;
    string answer = "";

    for (int i = 1; i <= sen1.length(); i++)
    {
        for (int j = 1; j <= sen2.length(); j++)
        {
            if (myMap[j][i] == idx)
            {
                answer += sen1[i - 1];
                idx += 1;
                break;
            }
            else
            {
                continue;
            }
        }
    }

    cout << answer.length() << endl;
    return 0;
}