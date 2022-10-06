#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[1001];
vector<int> myGraph[10001];

void DFS(int x)
{
    visited[x]=true;
    cout<<x<<" ";

    for(int i=0;i<myGraph[x].size();i++)
    {
        if(visited[myGraph[x][i]]==false)
        {
            DFS(myGraph[x][i]);
        }
    }
}

void BFS(int x)
{
    queue<int> Queue;
    Queue.push(x);
    visited[x]=false;

    while(!Queue.empty())
    {
        int current = Queue.front();
        Queue.pop();
        cout<<current<<" ";

        for(int i=0;i<myGraph[current].size();i++)
        {
            if(visited[myGraph[current][i]]==true)
            {
                visited[myGraph[current][i]]=false;
                Queue.push(myGraph[current][i]);
            }
        }
    }
}

int main()
{
    int n, m, start;
    cin>>n>>m>>start;

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;

        myGraph[a].push_back(b);
        myGraph[b].push_back(a);

    }

    for(int i=0;i<m;i++)
    {
        sort(myGraph[i].begin(), myGraph[i].end());
    }

    DFS(start);
    cout<<"\n";
    BFS(start);
    return 0;
}