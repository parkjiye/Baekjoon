#include <iostream>
#include <vector>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
vector<int> myMap[100005];
bool visited[100005];
int parent[100005];

void bfs()
{
    queue<int> q;
    q.push(1);
    visited[1] = true;
    parent[1] = -1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < myMap[cur].size(); i++)
        {
            int next = myMap[cur][i];
            if (!visited[next])
            {
                parent[next] = cur;
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    FASTIO();

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;

        myMap[x].push_back(y);
        myMap[y].push_back(x);
    }

    bfs();

    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << "\n";
    }

    return 0;
}