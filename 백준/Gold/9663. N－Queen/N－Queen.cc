#include <iostream>

using namespace std;

int N;
int myMap[16];
int answer = 0;

void nqueen(int cnt)
{
    if (cnt == N)
    {
        answer += 1;
        return;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            bool check = true;
            // 이전 컬럼들과 비교
            for (int j = 0; j < cnt; j++)
            {
                myMap[cnt] = i;
                if (myMap[j] == myMap[cnt] || ((j - cnt) == (myMap[j] - myMap[cnt])) || ((j - cnt) == (myMap[cnt] - myMap[j])))
                {
                    check = false;
                    break;
                }
            }

            if (check)
            {
                nqueen(cnt + 1);
            }
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        myMap[0] = i;
        nqueen(1);
    }

    cout << answer << endl;

    return 0;
}