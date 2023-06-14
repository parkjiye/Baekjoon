#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
vector<int> myMap[32005];
int inDegree[32005];

int main()
{
    FASTIO();
    cin >> N >> M;

    memset(inDegree, 0, sizeof(inDegree));

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        myMap[x].emplace_back(y);
        inDegree[y] += 1;
    }
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 1; i <= N; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        int cur = q.top();
        q.pop();
        cout << cur << " ";

        for (int j = 0; j < myMap[cur].size(); j++)
        {
            int next = myMap[cur][j];
            if (--inDegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    cout << endl;
    return 0;
}