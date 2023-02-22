#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int count;

int x, y;

int myMap[100001];
bool visited[100001];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    myMap[start] = 0;
    visited[start] = true;

    while (!q.empty())
    {
        if (myMap[y] != 0)
            break;
        int cur = q.front();
        q.pop();

        if (cur - 1 >= 0 && !visited[cur - 1])
        {
            q.push(cur - 1);
            visited[cur - 1] = true;
            myMap[cur - 1] = myMap[cur] + 1;
        }

        if (cur + 1 <= 100000 && !visited[cur + 1])
        {
            q.push(cur + 1);
            visited[cur + 1] = true;
            myMap[cur + 1] = myMap[cur] + 1;
        }

        if (cur * 2 <= 100000 && !visited[cur * 2])
        {
            q.push(cur * 2);
            visited[cur * 2] = true;
            myMap[cur * 2] = myMap[cur] + 1;
        }
    }
}

int main()
{
    cin >> x >> y;

    memset(myMap, 0, sizeof(myMap));

    bfs(x);

    cout << myMap[y] << endl;
}