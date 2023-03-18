#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

vector<int> myGraph[205];
bool visited[205];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start]=true;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int i=0;i<myGraph[cur].size();i++)
        {
            if(!visited[myGraph[cur][i]])
            {
                q.push(myGraph[cur][i]);
                visited[myGraph[cur][i]]=true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<computers.size();i++)
    {
        vector<int> cur = computers[i];
        
        for(int j=0;j<cur.size();j++)
        {
            if(i!=j && cur[j]!=0)
            {
                myGraph[i+1].push_back(j+1);
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            bfs(i);
            answer+=1;
        }
    }
    
    return answer;
}