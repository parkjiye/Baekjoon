#include <iostream>
#include <vector>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct belt
{
    int box;
    bool rb;
};

belt make_belt(int box, bool rb)
{
    belt temp;
    temp.box = box;
    temp.rb = rb;
    return temp;
}

int N, K;

belt myMap[105][2];

deque<belt> q;

int main()
{
    FASTIO();
    cin >> N >> K;

    for (int i = 0; i < 2 * N; i++)
    {
        int x;
        cin >> x;
        q.push_back(make_belt(x, false));
    }

    int day = 1;
    while (1)
    {
        //  한 칸 회전
        belt temp = q.back();
        q.pop_back();
        q.push_front(temp);

        if (q[N - 1].rb)
        {
            q[N - 1].rb = false;
        }

        // 가장 먼저 올라간 애부터 한 칸 이동

        if (q[N - 2].rb)
        {
        }
        for (int i = 2 * N - 1; i >= 0; i--)
        {
            if (q[i].rb && q[(i + 1) % (2 * N)].box >= 1 && !q[(i + 1) % (2 * N)].rb)
            {
                if (i == N - 2)
                {
                    if (q[i].rb)
                    {
                        q[N - 1].box -= 1;
                        q[N - 2].rb = false;
                    }
                }
                else
                {
                    q[i].rb = false;
                    q[(i + 1) % (2 * N)].box -= 1;
                    q[(i + 1) % (2 * N)].rb = true;
                }
            }
        }

        // 올리는 위치에 로봇을 올린다
        if (q.front().box >= 1)
        {
            q.front().box -= 1;
            q.front().rb = true;
        }

        int cnt = 0;

        for (int i = 0; i < 2 * N; i++)
        {
            if (q[i].box == 0)
            {
                cnt += 1;
            }
        }

        if (cnt >= K)
            break;
        else
            day += 1;
    }

    cout << day << endl;

    return 0;
}