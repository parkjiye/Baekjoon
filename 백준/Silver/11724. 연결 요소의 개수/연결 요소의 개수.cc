#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> myGraph[1000];
bool visited[1005];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < myGraph[cur].size(); i++)
        {
            if (!visited[myGraph[cur][i]])
            {
                q.push(myGraph[cur][i]);
                visited[myGraph[cur][i]] = true;
            }
        }
    }
}

int main()
{
    int N;
    int M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        myGraph[a].push_back(b);
        myGraph[b].push_back(a);
    }

    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            bfs(i);
            answer += 1;
        }
    }

    cout << answer << endl;
}