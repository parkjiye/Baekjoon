#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> myGraph[100001];
int line[100001];
int ans[100001];
bool visited[100001];
int order[100001];
int L=1;
bool comp(int a, int b)
{
    return order[a]<order[b];
}

void DFS(int x)
{
    visited[x]=true;
    ans[L++]=x;

    for(int i=0;i<myGraph[x].size();i++)
    {
        int current = myGraph[x][i];

        if(visited[current]==false)
        {
            DFS(current);
        }
    }
}

int main()
{
    int m;
    cin>>m;

    for(int i=1;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        myGraph[a].push_back(b);
        myGraph[b].push_back(a);

    }

    for(int i=1;i<=m;i++)
    {
        cin>>line[i];
        order[line[i]]=i;
    }

    for(int i=1;i<=m;i++)
    {
        sort(myGraph[i].begin(), myGraph[i].end(), comp);
    }

    DFS(1);
    
    for(int i=1;i<=m;i++)
    {
        if(line[i]!=ans[i])
        {
            cout<<0;
            return 0;
        }
    }
    cout<<1;
}