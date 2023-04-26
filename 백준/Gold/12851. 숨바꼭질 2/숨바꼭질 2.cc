#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N, K;
int myMap[100005];
int way[100005];

void bfs()
{
    queue<pair<int, int>> q;
    q.push({N, 0});
    way[N] = 1;

    while (!q.empty())
    {
        int cur = q.front().first;
        int sec = q.front().second;
        q.pop();

        if (cur == K)
            break;

        // X-1
        if (cur - 1 >= 0)
        {
            if (myMap[cur - 1] == 0 || myMap[cur - 1] == sec + 1)
            {
                q.push({cur - 1, sec + 1});
                myMap[cur - 1] = sec + 1;
                way[cur - 1] += 1;
            }
        }

        if (cur + 1 <= 100000)
        {
            if (myMap[cur + 1] == 0 || myMap[cur + 1] == sec + 1)
            {
                q.push({cur + 1, sec + 1});
                myMap[cur + 1] = sec + 1;
                way[cur + 1] += 1;
            }
        }

        if (cur * 2 <= 100000)
        {
            if (myMap[cur * 2] == 0 || myMap[cur * 2] == sec + 1)
            {
                q.push({cur * 2, sec + 1});
                myMap[cur * 2] = sec + 1;
                way[cur * 2] += 1;
            }
        }
    }
}

int main()
{
    cin >> N >> K;
    memset(myMap, 0, sizeof(myMap));
    memset(way, 0, sizeof(way));

    bfs();

    cout << myMap[K] << endl;
    cout << way[K] << endl;

    return 0;
}