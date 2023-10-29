#include <iostream>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

int main()
{
    FASTIO();
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    long answer = 0;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    if (pq.size() == 1)
    {
        cout << 0 << "\n";
        return 0;
    }

    while (!pq.empty())
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        answer += (first + second);

        if (!pq.empty())
        {
            pq.push(first + second);
        }

        // cout << answer << endl;
    }

    cout << answer << "\n";
}