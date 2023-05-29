#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int N;
    cin >> N;

    deque<int> q;

    for (int i = 1; i <= N; i++)
    {
        q.push_back(i);
    }

    while (q.size() != 1)
    {
        q.pop_front();
        int temp = q.front();
        q.pop_front();
        q.push_back(temp);
    }

    cout << q.front() << endl;
}