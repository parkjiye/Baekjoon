#include <iostream>
#include <deque>
#include <math.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

deque<int> wheels[4];

void move_clock(int w)
{
    int temp = wheels[w].back();
    wheels[w].pop_back();
    wheels[w].push_front(temp);
}

void move_clockwise(int w)
{
    int temp = wheels[w].front();
    wheels[w].pop_front();
    wheels[w].push_back(temp);
}

struct binding
{
    int left;
    int right;

    binding(int left, int right) : left(left), right(right) {}
    binding() {}
};

binding binds[4];

int main()
{
    FASTIO();

    for (int i = 0; i < 4; i++)
    {
        string sen;
        cin >> sen;

        for (int j = 0; j < 8; j++)
        {
            wheels[i].push_back(sen[j] - '0');
        }
    }

    int K;
    cin >> K;

    for (int k = 0; k < K; k++)
    {
        // 1인 경우 시계 방향, -1인 경우 반시계 방향
        // 0은 N, 1은 S
        int w, d;
        cin >> w >> d;

        binds[0].right = wheels[0][2];
        binds[1].left = wheels[1][6];
        binds[1].right = wheels[1][2];
        binds[2].left = wheels[2][6];
        binds[2].right = wheels[2][2];
        binds[3].left = wheels[3][6];

        if (d == 1)
        {
            int temp = wheels[w - 1].back();
            wheels[w - 1].pop_back();
            wheels[w - 1].push_front(temp);
        }
        else
        {
            int temp = wheels[w - 1].front();
            wheels[w - 1].pop_front();
            wheels[w - 1].push_back(temp);
        }

        if (w == 1)
        {
            for (int i = 0; i < 3; i++)
            {
                if (binds[i].right == binds[i + 1].left)
                {
                    break;
                }
                else
                {
                    if (d == 1)
                    {
                        move_clockwise(i + 1);
                        d = -1;
                    }
                    else
                    {
                        move_clock(i + 1);
                        d = 1;
                    }
                }
            }
        }
        else if (w == 4)
        {
            for (int i = 3; i >= 1; i--)
            {
                if (binds[i].left == binds[i - 1].right)
                {
                    break;
                }
                else
                {
                    if (d == 1)
                    {
                        move_clockwise(i - 1);
                        d = -1;
                    }
                    else
                    {
                        move_clock(i - 1);
                        d = 1;
                    }
                }
            }
        }
        else if (w == 2)
        {
            if (binds[0].right != binds[1].left)
            {
                if (d == 1)
                {
                    move_clockwise(0);
                }
                else
                {
                    move_clock(0);
                }
            }

            for (int i = 1; i < 3; i++)
            {
                if (binds[i].right == binds[i + 1].left)
                {
                    break;
                }
                else
                {
                    if (d == 1)
                    {
                        move_clockwise(i + 1);
                        d = -1;
                    }
                    else
                    {
                        move_clock(i + 1);
                        d = 1;
                    }
                }
            }
        }

        else
        {
            if (binds[2].right != binds[3].left)
            {
                if (d == 1)
                {
                    move_clockwise(3);
                }
                else
                {
                    move_clock(3);
                }
            }
            for (int i = 2; i >= 1; i--)
            {
                if (binds[i].left == binds[i - 1].right)
                {
                    break;
                }
                else
                {
                    if (d == 1)
                    {
                        move_clockwise(i - 1);
                        d = -1;
                    }
                    else
                    {
                        move_clock(i - 1);
                        d = 1;
                    }
                }
            }
        }
    }

    int score = 0;

    for (int k = 0; k < 4; k++)
    {

        if (wheels[k].front())
        {
            score += pow(2, k);
        }
    }

    cout << score << endl;
}