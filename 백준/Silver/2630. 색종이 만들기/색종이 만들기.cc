#include <iostream>
#include <string.h>
using namespace std;

int myMap[128][128];
int w_cnt;
int b_cnt;

void paper(int x, int y, int N)
{
    int cnt = 0;

    for (int i = x; i < x + N; i++)
    {
        for (int j = y; j < y + N; j++)
        {
            if (myMap[i][j])
                cnt += 1;
        }
    }

    if (!cnt)
        w_cnt += 1;
    else if (cnt == N * N)
        b_cnt += 1;
    else
    {
        paper(x, y, N / 2);
        paper(x + N / 2, y, N / 2);
        paper(x, y + N / 2, N / 2);
        paper(x + N / 2, y + N / 2, N / 2);
    }

    return;
}

int main()
{
    int num;
    cin >> num;
    memset(myMap, 0, sizeof(myMap));

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            // cout << i << " " << j << endl;
            int a;
            cin >> a;
            myMap[i][j] = a;
        }
    }
    paper(0, 0, num);

    cout << w_cnt << endl;

    cout << b_cnt << endl;

    return 0;
}
