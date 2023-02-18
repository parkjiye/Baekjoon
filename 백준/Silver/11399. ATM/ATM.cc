#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int num;
    cin >> num;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < num; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    int time = 0;
    int prev = 0;

    int answer = 0;

    for (int i = 0; i < num; i++)
    {
        answer += pq.top();
        if (i != 0)
        {
            answer += prev;
        }
        prev += pq.top();
        pq.pop();
        // cout << prev << " " << answer << endl;
    }

    cout << answer << endl;
}