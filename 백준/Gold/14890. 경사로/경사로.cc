#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, L;
int myMap[105][105];
bool slide[105][105];

struct p
{
    int x;
    int y;
    int h;

    p(int x, int y, int h) : x(x), y(y), h(h) {}
    p() {}
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    FASTIO();
    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;
            myMap[i][j] = x;
        }
    }

    memset(slide, 0, sizeof(slide));

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        bool ispossible = true;

        for (int j = 0; j < N - 1; j++)
        {
            if (abs(myMap[i][j] - myMap[i][j + 1]) <= 1)
            {
                if (myMap[i][j] - myMap[i][j + 1] == 1)
                {
                    bool s = true;
                    int height = myMap[i][j + 1];

                    for (int k = 0; k < L; k++)
                    {
                        if (j + k + 1 >= N || slide[i][j + k + 1] || myMap[i][j + k + 1] != height)
                        {
                            ispossible = false;
                            s = false;
                            break;
                        }
                    }

                    if (s)
                    {
                        for (int k = 0; k < L; k++)
                        {
                            slide[i][j + k + 1] = true;
                        }
                    }
                }

                if (myMap[i][j] - myMap[i][j + 1] == -1)
                {
                    bool s = true;
                    int height = myMap[i][j];

                    for (int k = 0; k < L; k++)
                    {
                        if (j - k < 0 || slide[i][j - k] || myMap[i][j - k] != height)
                        {
                            ispossible = false;
                            s = false;
                            break;
                        }
                    }

                    if (s)
                    {
                        for (int k = 0; k < L; k++)
                        {
                            slide[i][j - k] = true;
                        }
                    }
                }
            }
            else
            {
                ispossible = false;
                break;
            }
        }

        if (ispossible)
        {
            answer += 1;
        }
    }

    memset(slide, 0, sizeof(slide));

    for (int i = 0; i < N; i++)
    {
        bool ispossible = true;

        for (int j = 0; j < N - 1; j++)
        {
            if (abs(myMap[j][i] - myMap[j + 1][i]) <= 1)
            {
                if (myMap[j][i] - myMap[j + 1][i] == 1)
                {
                    bool s = true;
                    int height = myMap[j + 1][i];

                    for (int k = 0; k < L; k++)
                    {
                        if (j + k + 1 >= N || slide[j + k + 1][i] || myMap[j + k + 1][i] != height)
                        {
                            ispossible = false;
                            s = false;
                            break;
                        }
                    }

                    if (s)
                    {
                        for (int k = 0; k < L; k++)
                        {
                            slide[j + k + 1][i] = true;
                        }
                    }
                }

                if (myMap[j][i] - myMap[j + 1][i] == -1)
                {
                    bool s = true;
                    int height = myMap[j][i];

                    for (int k = 0; k < L; k++)
                    {
                        if (j - k < 0 || slide[j - k][i] || myMap[j - k][i] != height)
                        {
                            ispossible = false;
                            s = false;
                            break;
                        }
                    }

                    if (s)
                    {
                        for (int k = 0; k < L; k++)
                        {
                            slide[j - k][i] = true;
                        }
                    }
                }
            }
            else
            {
                ispossible = false;
                break;
            }
        }

        if (ispossible)
        {
            answer += 1;
        }
    }

    cout << answer << endl;
}