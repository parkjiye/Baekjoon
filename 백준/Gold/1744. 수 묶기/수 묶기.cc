#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

priority_queue<int> pos_pq;
priority_queue<int, vector<int>, greater<int>> neg_pq;

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        if (x <= 0)
        {
            neg_pq.push(x);
        }
        else
        {
            pos_pq.push(x);
        }
    }

    long answer = 0;

    while (!pos_pq.empty())
    {
        if (pos_pq.size() == 1)
        {
            answer += pos_pq.top();
            pos_pq.pop();
        }
        else
        {
            int first = pos_pq.top();
            pos_pq.pop();
            int second = pos_pq.top();
            pos_pq.pop();

            if (first + second < first * second)
            {
                answer += first * second;
            }
            else
            {
                answer += first + second;
            }
        }
    }

    // cout << answer << "\n";

    while (!neg_pq.empty())
    {
        if (neg_pq.size() == 1)
        {
            answer += neg_pq.top();
            neg_pq.pop();
        }
        else
        {
            int first = neg_pq.top();
            neg_pq.pop();
            int second = neg_pq.top();
            neg_pq.pop();

            if (first + second < first * second)
            {
                answer += first * second;
            }
            else
            {
                answer += first + second;
            }
        }
    }

    cout << answer << "\n";
}