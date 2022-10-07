#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> myGraph[100001];
int line[100001];
int order[100001];
int ans[100001];
bool visited[100001];
int L=0;

bool comp(int a, int b)
{
    return order[a]<order[b];
}

void BFS()
{
    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        visited[current]=true;
        ans[L++]=current;

        for(int i=0;i<myGraph[current].size();i++)
        {
            if(visited[myGraph[current][i]]==false)
            {
                q.push(myGraph[current][i]);
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++)
    {
        int a, b;
        cin>>a>>b;
        myGraph[a].push_back(b);
        myGraph[b].push_back(a);
    }

    for(int i=0;i<n;i++)
    {
        cin>>line[i];
        order[line[i]]=i;
    }

    for(int i=1;i<=n;i++)
    {
        sort(myGraph[i].begin(), myGraph[i].end(), comp);
    }

    BFS();

    for(int i=0;i<n;i++)
    {
        if(line[i]!=ans[i])
        {
            cout<<"0";
            return 0;
        }
    }

    cout<<"1";
    return 0;
}