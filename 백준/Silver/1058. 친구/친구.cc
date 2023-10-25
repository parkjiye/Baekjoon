#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
vector<int> myMap[55];
int friends[55];
bool visited[55];

void bfs(int start)
{
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        for (int i = 0; i < myMap[cur].size(); i++)
        {
            int next = myMap[cur][i];
            if (!visited[next] && dist + 1 <= 2)
            {
                visited[next] = true;
                q.push({next, dist + 1});
                friends[start] += 1;
            }
        }
    }
}

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++)
        {
            if (s[j] == 'Y')
            {
                myMap[i + 1].push_back(j + 1);
                myMap[j + 1].push_back(i + 1);
            }
        }
    }

    memset(friends, 0, sizeof(friends));

    int ans = 0;

    for (int i = 1; i <= N; i++)
    {
        bfs(i);

        if (friends[i] > ans)
        {
            ans = friends[i];
        }
    }

    cout << ans << "\n";
}