#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int inDegree[1005];
vector<int> myMap[1005];
vector<int> answer;

int main()
{
    FASTIO();
    memset(inDegree, 0, sizeof(inDegree));

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        for (int j = 0; j < x - 1; j++)
        {
            int z;
            cin >> z;

            myMap[y].push_back(z);
            inDegree[z] += 1;

            y = z;
        }
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
        if (q.empty())
        {
            cout << 0 << endl;
            return 0;
        }

        int cur = q.front();
        q.pop();

        answer.push_back(cur);

        for (int k = 0; k < myMap[cur].size(); k++)
        {
            int next = myMap[cur][k];
            if (--inDegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}