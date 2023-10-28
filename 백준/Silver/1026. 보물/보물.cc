#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

priority_queue<int, vector<int>, greater<int>> pq_a;
priority_queue<int> pq_b;

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        pq_a.push(x);
    }

    for (int i = 0; i < N; i++)
    {
        int y;
        cin >> y;

        pq_b.push(y);
    }

    int answer = 0;

    while (!pq_b.empty())
    {
        answer += pq_b.top() * pq_a.top();
        pq_b.pop();
        pq_a.pop();
    }

    cout << answer << "\n";
}