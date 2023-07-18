#include <iostream>
#include <queue>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int T, N;
int myGraph[100005];
bool visited[100005];
bool cycle[100005];
int ans;

void dfs(int cur)
{
    visited[cur] = true;
    int next = myGraph[cur];

    if (!visited[next])
    {
        dfs(next);
    }
    else if (!cycle[next])
    {
        for (int i = next; i != cur; i = myGraph[i])
        {
            ans += 1;
        }
        ans += 1;
    }
    cycle[cur] = true;
}

int main()
{
    FASTIO();

    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> N;
        ans = 0;

        memset(visited, 0, sizeof(visited));
        memset(cycle, 0, sizeof(cycle));

        for (int i = 1; i <= N; i++)
        {
            int x;
            cin >> x;

            myGraph[i] = x;
        }

        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }

        cout << N - ans << "\n";
    }
}