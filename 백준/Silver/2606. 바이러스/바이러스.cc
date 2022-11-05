#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

vector<int> myGraph[100];
bool visited[100];

void bfs()
{
    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
        int cur;
        cur=q.front();
        q.pop();
        visited[cur]=true;

        for(int i=0;i<myGraph[cur].size();i++)
        {
            if(!visited[myGraph[cur][i]])
            {
                //cout<<myGraph[cur][i]<<endl;
                q.push(myGraph[cur][i]);
            }
        }
    }
}

int main()
{
    int count;
    int connect;

    cin>>count>>connect;

    for(int i=0;i<connect;i++)
    {
        int a, b;
        cin>>a>>b;
        
        myGraph[a].push_back(b);
        myGraph[b].push_back(a);
    }
    memset(visited, 0, sizeof(visited));

    bfs();

    int answer=0;

    for(int i=2;i<=count;i++)
    {
        //cout<<visited[i]<<endl;

        if(visited[i])
        {
            answer+=1;
        }
    }

    cout<<answer<<endl;
}