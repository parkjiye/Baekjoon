#include <iostream>
#include <queue>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

string S, T;

void bfs()
{
    queue<string> q;
    q.push(T);

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();

        if (cur == S)
        {
            cout << 1 << "\n";
            return;
        }
        else if (cur.length() < S.length())
        {
            cout << 0 << "\n";
            return;
        }
        else
        {

            if (cur[cur.length() - 1] == 'A')
            {
                q.push(cur.substr(0, cur.length() - 1));
            }

            if (cur[0] == 'B')
            {
                cur = cur.substr(1, cur.length());
                reverse(cur.begin(), cur.end());
                q.push(cur);
            }
        }
    }

    cout << 0 << "\n";
    return;
}

int main()
{
    FASTIO();
    cin >> S >> T;

    bfs();
}