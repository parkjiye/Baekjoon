// 1) 인접한 값의 차이가 x이상 y이하인 부분을 모두 구한다
// 2) 이어진 부분을 그룹화한다
// 3) 각 그룹에 속한 슬라임질량의 평균값을 구한다
// 4) 슬라임의 질량을 업데이트 한다

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int myMap[51][51];
int n, l, r;

bool check[51][51];
int group[51][51];

int get_abs(int result)
{
    if (result > 0)
        return result;
    else
        return -result;
}

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

int sum;
int answer=0;
int result[51 * 51], resultLen;

int DFS(int curY, int curX)
{
    check[curY][curX] = true;
    int value = 1;
    sum += myMap[curY][curX];
    group[curY][curX] = resultLen;

    for (int k = 0; k < 4; k++)
    {
        int nextY = curY + dy[k];
        int nextX = curX + dx[k];

        if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n)
        {
            if (!check[nextY][nextX] && l <= get_abs(myMap[curY][curX] - myMap[nextY][nextX]) && get_abs(myMap[curY][curX] - myMap[nextY][nextX])<=r)
            {
                value += DFS(nextY, nextX);
            }
        }
    }

    return value;
}

bool groupcheck()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(group[i][j]!=-1) return true;
        }
    }

    return false;

}

int main()
{
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> myMap[i][j];
        }
    }

    while (1)
    {
        memset(check, 0, sizeof(check));
        resultLen = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!check[i][j])
                {
                    sum = 0;
                    int value = DFS(i, j);

                    if (value > 1)
                    {
                        result[resultLen] = sum / value;
                        resultLen++;
                    }
                    else
                    {
                        group[i][j] = -1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(group[i][j]!=-1)
                {
                    int w = result[group[i][j]];
                    myMap[i][j] = w;
                }
            }
        }

        /*for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << myMap[i][j] << " ";
            }

            cout << endl;
        }

        cout << endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << group[i][j] << " ";
            }

            cout << endl;
        }*/

        if(groupcheck()) 
        {
            answer++;
            continue;
        }
        else {
            cout<<answer<<endl;
            break;
        }

        
    }
}