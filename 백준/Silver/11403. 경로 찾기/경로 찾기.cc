#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

int N;
vector<int> myGraph[100];
bool visited[100];

void bfs(int start)
{
    queue<int> q;
    q.push(start);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int k=0;k<myGraph[cur].size();k++)
        {
            if(!visited[myGraph[cur][k]])
            {
                q.push(myGraph[cur][k]);
                visited[myGraph[cur][k]]=true;
            }
        }
    }
}

int main()
{
    cin>>N;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int num;
            cin>>num;

            if(num==1)
            {
                myGraph[i].push_back(j);
            }
        }
    }

    for(int i=0;i<N;i++)
    {
        memset(visited, 0, sizeof(visited));
        bfs(i);

        for(int j=0;j<N;j++)
        {
            cout<<visited[j]<<" ";
        }
        cout<<endl;
    }
}