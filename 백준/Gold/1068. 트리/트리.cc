#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

vector<int> myMap[50];
bool visited[51];
int N;
int answer = 0;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < myMap[cur].size(); i++)
        {
            if (!visited[myMap[cur][i]])
            {
                q.push(myMap[cur][i]);
                visited[myMap[cur][i]] = true;
            }
        }
    }
}

void cnt(int start)
{
    if (!visited[start])
    {
        int leaf = 0;
        for (int i = 0; i < myMap[start].size(); i++)
        {
            if (!visited[myMap[start][i]])
            {
                cnt(myMap[start][i]);
            }
            else
            {
                leaf += 1;
            }
        }

        if (leaf == myMap[start].size())
        {
            answer += 1;
        }
    }
}

int main()
{
    cin >> N;

    memset(myMap, 0, sizeof(myMap));

    vector<int> idx;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        idx.push_back(num);
    }

    int root;

    for (int i = 0; i < N; i++)
    {
        if (idx[i] != -1)
        {
            myMap[idx[i]].push_back(i);
        }
        else
        {
            root = i;
        }
    }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int k = 0; k < myMap[i].size(); k++)
    //     {
    //         cout << myMap[i][k] << " ";
    //     }
    //     cout << endl;
    // }

    int cut;
    cin >> cut;

    bfs(cut);

    // cout << "dafd" << endl;

    cnt(root);

    cout << answer << endl;
}