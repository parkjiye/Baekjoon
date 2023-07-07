#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int heart_x;
int heart_y;

char myMap[1005][1005];

void find_heart()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int next_x = i + dx[k];
                int next_y = j + dy[k];

                if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < N && myMap[next_x][next_y] == '*')
                {
                    cnt += 1;
                }
                else
                {
                    break;
                }
            }

            if (cnt == 4)
            {
                cout << i + 1 << " " << j + 1 << endl;
                heart_x = i;
                heart_y = j;

                return;
            }
        }
    }
}

struct part
{
    int x;
    int y;

    part(int x, int y) : x(x), y(y) {}
    part() {}
};

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char x;
            cin >> x;

            myMap[i][j] = x;
        }
    }

    find_heart();

    // 왼쪽 팔
    part left_arm = part(heart_x, heart_y - 1);
    int left_arm_len = 1;

    while (--left_arm.y >= 0)
    {
        if (myMap[left_arm.x][left_arm.y] == '*')
        {
            left_arm_len += 1;
        }
        else
        {
            break;
        }
    }

    cout << left_arm_len << " ";

    // 오른쪽 팔
    part right_arm = part(heart_x, heart_y + 1);
    int right_arm_len = 1;

    while (++right_arm.y < N)
    {
        if (myMap[right_arm.x][right_arm.y] == '*')
        {
            right_arm_len += 1;
        }
        else
        {
            break;
        }
    }

    cout << right_arm_len << " ";

    // 허리
    part head = part(heart_x + 1, heart_y);
    int head_len = 1;

    while (++head.x < N)
    {
        if (myMap[head.x][head.y] == '*')
        {
            head_len += 1;
        }
        else
        {
            break;
        }
    }

    cout << head_len << " ";

    head.x--;

    // 왼쪽 다리
    part left_leg = part(head.x + 1, head.y - 1);
    int left_leg_len = 1;

    while (++left_leg.x < N)
    {
        if (myMap[left_leg.x][left_leg.y] == '*')
        {
            left_leg_len += 1;
        }
        else
        {
            break;
        }
    }

    cout << left_leg_len << " ";

    // 오른쪽 다리
    part right_leg = part(head.x + 1, head.y + 1);
    int right_leg_len = 1;

    while (++right_leg.x < N)
    {
        if (myMap[right_leg.x][right_leg.y] == '*')
        {
            right_leg_len += 1;
        }
        else
        {
            break;
        }
    }

    cout << right_leg_len << endl;
}