#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N, K;
int myMap[100001];
bool visited[100001];

void bfs()
{
    queue<int> q;
    q.push(N);
    visited[N] = true;
    myMap[N] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // cout << cur << endl;

        if (cur * 2 <= 100000)
        {
            if (visited[cur * 2] && myMap[cur * 2] > myMap[cur])
            {
                myMap[cur * 2] = myMap[cur] * 2;
                q.push(cur * 2);
            }
            if (!visited[cur * 2])
            {
                visited[cur * 2] = true;
                myMap[cur * 2] = myMap[cur];
                q.push(cur * 2);
            }
        }
        if (cur - 1 >= 0)
        {
            if (visited[cur - 1] && myMap[cur - 1] > myMap[cur] + 1)
            {
                myMap[cur + 1] = myMap[cur] + 1;
                q.push(cur + 1);
            }
            if (!visited[cur - 1])
            {
                visited[cur - 1] = true;
                myMap[cur - 1] = myMap[cur] + 1;
                q.push(cur - 1);
            }
        }
        if (cur + 1 <= 100000)
        {
            if (visited[cur + 1] && myMap[cur + 1] > myMap[cur] + 1)
            {
                myMap[cur + 1] = myMap[cur] + 1;
                q.push(cur + 1);
            }
            if (!visited[cur + 1])
            {
                visited[cur + 1] = true;
                myMap[cur + 1] = myMap[cur] + 1;
                q.push(cur + 1);
            }
        }
        }
}

int main()
{
    cin >> N >> K;
    memset(visited, 0, sizeof(visited));
    memset(myMap, 0, sizeof(myMap));
    bfs();
    cout << myMap[K] << endl;
    return 0;
}