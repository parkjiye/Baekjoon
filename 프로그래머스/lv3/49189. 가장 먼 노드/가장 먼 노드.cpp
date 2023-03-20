#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> myGraph[20005];
vector<int> dist(20005, 0);
bool visited[20005];

int solution(int n, vector<vector<int>> edge) {
    
    for(int i=0;i<edge.size();i++)
    {
        vector<int> e = edge[i];
        myGraph[e[0]].push_back(e[1]);
        myGraph[e[1]].push_back(e[0]);
    }
    
    queue<int> q;
    q.push(1);
    visited[1]=true;
    dist[1]=0;
    
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
                dist[myGraph[cur][i]]=dist[cur]+1;
            }
        }
    }
    
    int max = *max_element(dist.begin(), dist.end());
    int answer=0;
    
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==max) answer+=1;
    }
    
    return answer;
}