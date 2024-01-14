#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <math.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int answer = 1000000;
int pop[12];
int path[12];
bool selected[12];
bool visited[12];
vector<int> myGraph[12];

int bfs()
{
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(path[0]);
    visited[path[0]] = true;

    int a_sum = pop[path[0]];

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < myGraph[cur].size(); i++)
        {
            int next = myGraph[cur][i];
            if (selected[next] && !visited[next])
            {
                q.push(next);
                visited[next] = true;
                a_sum += pop[next];
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i] && selected[i])
        {
            return -1;
        }
    }

    int b_sum;

    for (int i = 1; i <= N; i++)
    {
        if (!selected[i])
        {
            q.push(i);
            visited[i] = true;
            b_sum = pop[i];
            break;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < myGraph[cur].size(); i++)
        {
            int next = myGraph[cur][i];

            if (!selected[next] && !visited[next])
            {
                q.push(next);
                visited[next] = true;
                b_sum += pop[next];
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (!selected[i] && !visited[i])
        {
            return -1;
        }
    }

    return abs(a_sum - b_sum);
}

void combination(int idx, int cnt)
{
    if (idx == cnt)
    {
        memset(selected, 0, sizeof(selected));

        for (int i = 0; i < cnt; i++)
        {
            // cout << path[i] << " ";
            selected[path[i]] = true;
        }
        // cout << "\n";

        int num = bfs();

        if (num < answer && num != -1)
        {
            answer = num;
        }

        // cout << num << "\n";
        return;
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            if (idx == 0 || path[idx - 1] < i)
            {
                path[idx] = i;
                combination(idx + 1, cnt);
            }
        }
    }
}

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;

        pop[i] = x;
    }

    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;

        for (int j = 0; j < x; j++)
        {
            int y;
            cin >> y;
            myGraph[i].push_back(y);
        }
    }

    for (int i = 1; i <= N / 2; i++)
    {
        combination(0, i);
    }

    if (answer == 1000000)
    {
        answer = -1;
    }

    cout << answer << "\n";
}