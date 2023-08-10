#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int operands[11];
int operators[4];

long long int ans_max = -1000000001;
long long int ans_min = 1000000001;

void back_tracking(long long int val, int idx)
{
    if (idx == N)
    {
        if (val > ans_max)
        {
            ans_max = val;
        }

        if (val < ans_min)
        {
            ans_min = val;
        }

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (operators[i] > 0)
        {
            operators[i] -= 1;

            if (i == 0)
            {
                back_tracking(val + operands[idx], idx + 1);
            }
            else if (i == 1)
            {
                back_tracking(val - operands[idx], idx + 1);
            }
            else if (i == 2)
            {
                back_tracking(val * operands[idx], idx + 1);
            }
            else
            {
                back_tracking(val / operands[idx], idx + 1);
            }

            operators[i] += 1;
        }
    }
}

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        operands[i] = x;
    }

    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;

        operators[i] = x;
    }

    back_tracking(operands[0], 1);

    cout << ans_max << endl;
    cout << ans_min << endl;
}