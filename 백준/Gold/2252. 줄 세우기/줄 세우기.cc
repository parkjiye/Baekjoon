#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<int> myMap[35000];
int inDegree[35000];

int main()
{
    FASTIO();

    int N, M;
    cin >> N >> M;

    memset(inDegree, 0, sizeof(inDegree));

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        myMap[x].emplace_back(y);
        inDegree[y] += 1;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    for (int i = 0; i < N; i++)
    {
        int cur = q.front();
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
}