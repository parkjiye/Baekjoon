#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    deque<int> dq;

    for (int i = 0; i < N; i++)
    {
        dq.push_back(i + 1);
    }
    cout << "<";

    while (dq.size() != 1)
    {
        for (int i = 0; i < K - 1; i++)
        {
            int x = dq.front();
            dq.pop_front();
            dq.push_back(x);
        }

        cout << dq.front() << ", ";
        dq.pop_front();
    }

    cout << dq.front() << ">\n";
}