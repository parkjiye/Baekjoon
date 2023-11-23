#include <iostream>
#include <vector>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;

vector<int> myGraph[2005];
bool found = false;
bool visited[2005];

void dfs(int idx, int cnt)
{
    if (cnt == 4)
    {
        found = true;
        return;
    }
    else
    {
        for (int i = 0; i < myGraph[idx].size(); i++)
        {
            if (found)
            {
                return;
            }
            if (!visited[myGraph[idx][i]])
            {
                visited[myGraph[idx][i]] = true;
                dfs(myGraph[idx][i], cnt + 1);
                visited[myGraph[idx][i]] = false;
            }
        }
    }
}
int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        myGraph[x].push_back(y);
        myGraph[y].push_back(x);
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++)
    {
        if (!found)
        {
            visited[i] = true;
            dfs(i, 0);
            visited[i] = false;
        }
    }

    if (found)
    {
        cout << 1 << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
}