#include <iostream>
#include <queue>
#define MAX 1000000000
using namespace std;

int A, B;

long long bfs()
{
    queue<pair<int, int>> q;
    q.push({A, 0});

    while (!q.empty())
    {
        int cur = q.front().first;
        long long cnt = q.front().second;

        q.pop();

        if (cur == B)
        {
            return cnt + 1;
        }

        if (cur * 2 <= MAX)
        {
            q.push({cur * 2, cnt + 1});
        }

        string tmp = to_string(cur) + "1";

        if (tmp.length() <= 9)
        {
            q.push({stoi(tmp), cnt + 1});
        }
    }

    return -1;
}

int main()
{
    cin >> A >> B;

    cout << bfs() << endl;

    return 0;
}