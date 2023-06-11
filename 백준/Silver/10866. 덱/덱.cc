#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

int main()
{
    FASTIO();

    cin >> N;

    deque<int> dq;

    for (int i = 0; i < N; i++)
    {
        string sen;
        cin >> sen;

        if (sen == "push_front")
        {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if (sen == "push_back")
        {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if (sen == "pop_front")
        {
            if (dq.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }
        else if (sen == "pop_back")
        {
            if (dq.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        }
        else if (sen == "size")
        {
            cout << dq.size() << endl;
        }
        else if (sen == "empty")
        {
            cout << dq.empty() << endl;
        }
        else if (sen == "front")
        {
            if (dq.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << dq.front() << endl;
            }
        }
        else
        {
            if (dq.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << dq.back() << endl;
            }
        }
    }
}