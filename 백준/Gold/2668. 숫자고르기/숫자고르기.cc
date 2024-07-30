#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

set<int> answer;
vector<int> v;
bool visited[105];

void dfs(int start)
{
    memset(visited, 0, sizeof(visited));

    vector<int> tmp;
    tmp.push_back(start);
    visited[start] = true;

    int cur = start;

    while (1)
    {
        int next = v[cur];

        if (next == start)
        {
            for (int i = 0; i < tmp.size(); i++)
            {
                answer.insert(tmp[i]);
            }
            return;
        }

        if (!visited[next] && answer.find(next) == answer.end())
        {
            visited[next] = true;
            tmp.push_back(next);
            cur = next;
        }
        else
        {
            return;
        }
    }
}

int main()
{
    FASTIO();
    int N;
    cin >> N;

    v.push_back(0);

    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }

    for (int i = 1; i <= N; i++)
    {
        if (answer.find(i) != answer.end())
        {
            continue;
        }

        if (i == v[i])
        {
            answer.insert(i);
        }
        else
        {
            dfs(i);
        }
    }

    cout << answer.size() << "\n";

    for (auto it = answer.begin(); it != answer.end(); it++)
    {
        cout << *it << "\n";
    }
}