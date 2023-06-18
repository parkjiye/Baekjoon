#include <iostream>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

int main()
{
    FASTIO();
    cin >> N;

    queue<int> q;

    for (int i = 0; i < N; i++)
    {
        string sen;
        cin >> sen;

        if (sen == "push")
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (sen == "pop")
        {
            if (q.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            cout << q.front() << "\n";
            q.pop();
        }
        else if (sen == "size")
        {
            cout << q.size() << "\n";
        }
        else if (sen == "empty")
        {
            cout << q.empty() << "\n";
        }
        else if (sen == "front")
        {
            if (q.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            cout << q.front() << "\n";
        }
        else
        {
            if (q.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            cout << q.back() << "\n";
        }
    }
}