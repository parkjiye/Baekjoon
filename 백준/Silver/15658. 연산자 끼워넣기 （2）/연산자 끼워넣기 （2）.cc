#include <iostream>

using namespace std;

int N;
long long int max_ans = -1000000001;
long long int min_ans = 1000000001;

int operands[12] = {
    0,
};
int operators[4] = {
    0,
};

void backtracking(int idx, int val)
{
    if (idx == N)
    {
        if (val > max_ans)
        {
            max_ans = val;
        }

        if (val < min_ans)
        {
            min_ans = val;
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
                backtracking(idx + 1, val + operands[idx]);
            }
            else if (i == 1)
            {
                backtracking(idx + 1, val - operands[idx]);
            }
            else if (i == 2)
            {
                backtracking(idx + 1, val * operands[idx]);
            }
            else
            {
                backtracking(idx + 1, val / operands[idx]);
            }

            operators[i] += 1;
        }
    }
}

int main()
{
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

    backtracking(1, operands[0]);

    cout << max_ans << endl;
    cout << min_ans << endl;
}