#include <iostream>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, W, L;

int main()
{
    FASTIO();
    cin >> N >> W >> L;

    deque<int> dq;

    for (int i = 0; i < W; i++)
    {
        dq.push_back(0);
    }

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        int cur;
        cin >> cur;

        while (1)
        {
            int sum = 0;
            answer += 1;

            for (int j = 0; j < dq.size(); j++)
            {
                sum += dq[j];
            }

            if (sum - dq.front() + cur > L)
            {
                dq.pop_front();
                dq.push_back(0);
            }
            else
            {
                dq.pop_front();
                dq.push_back(cur);
                break;
            }
        }
    }

    while (!dq.empty())
    {
        int sum = 0;

        for (int j = 0; j < dq.size(); j++)
        {
            sum += dq[j];
        }

        if (sum != 0)
        {
            answer += 1;
            dq.pop_front();
        }
        else
        {
            break;
        }
    }

    cout << answer << endl;
}