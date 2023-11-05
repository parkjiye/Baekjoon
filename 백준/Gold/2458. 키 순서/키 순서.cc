#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;

vector<int> myGraph[505];
vector<int> myGraph2[505];
bool visited[505];

int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        myGraph[a].push_back(b);
        myGraph2[b].push_back(a);
    }

    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        memset(visited, 0, sizeof(visited));

        int taller = 0;
        int shorter = 0;

        queue<int> q;
        q.push(i);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int k = 0; k < myGraph[cur].size(); k++)
            {
                if (!visited[myGraph[cur][k]])
                {
                    q.push(myGraph[cur][k]);
                    visited[myGraph[cur][k]] = true;
                    taller += 1;
                }
            }
        }

        q.push(i);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int k = 0; k < myGraph2[cur].size(); k++)
            {
                if (!visited[myGraph2[cur][k]])
                {
                    q.push(myGraph2[cur][k]);
                    visited[myGraph2[cur][k]] = true;
                    shorter += 1;
                }
            }
        }

        // cout << taller << " " << shorter << "\n";

        if (taller + shorter == N - 1)
        {
            answer += 1;
        }
    }

    cout << answer << "\n";
}