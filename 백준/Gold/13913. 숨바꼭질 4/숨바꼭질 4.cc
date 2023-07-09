#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int N, K;
int myMap[100005];
bool visited[100005];

struct pos
{
    int idx;
    vector<int> v;

    pos(int idx, vector<int> v) : idx(idx), v(v) {}
    pos() {}
};

int main()
{
    cin >> N >> K;

    queue<pos> q;
    vector<int> v;
    memset(visited, 0, sizeof(visited));

    if (N > K)
    {
        cout << N - K << endl;
        for (int i = N; i >= K; i--)
        {
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }

    v.push_back(N);
    q.push(pos(N, v));
    visited[N] = true;

    while (!q.empty())
    {
        int cur = q.front().idx;
        vector<int> list = q.front().v;
        q.pop();

        if (cur == K)
        {
            cout << list.size() - 1 << endl;

            for (int i = 0; i < list.size(); i++)
            {
                cout << list[i] << " ";
            }
            cout << endl;

            return 0;
        }

        if (cur - 1 >= 0 && !visited[cur - 1])
        {
            visited[cur - 1] = true;
            vector<int> temp = list;
            temp.push_back(cur - 1);
            q.push(pos(cur - 1, temp));
        }
        if (cur + 1 <= 100000 && !visited[cur + 1])
        {
            visited[cur + 1] = true;
            vector<int> temp = list;
            temp.push_back(cur + 1);
            q.push(pos(cur + 1, temp));
        }
        if (cur * 2 <= 100000 && !visited[cur * 2])
        {
            visited[cur + 1] = true;
            vector<int> temp = list;
            temp.push_back(cur * 2);
            q.push(pos(cur * 2, temp));
        }
    }
}