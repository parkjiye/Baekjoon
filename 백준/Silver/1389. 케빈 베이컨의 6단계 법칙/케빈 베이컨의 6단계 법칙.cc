#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

int N, M;

vector<int> myGraph[101];
int kevin[101];
int dist[101];
bool visited[101];

struct p
{
    int x;
    int dis;
};

p make_p(int x, int dis)
{
    p temp;
    temp.x = x;
    temp.dis = dis;

    return temp;
};

void bfs(p start)
{
    queue<p> q;
    q.push(start);
    visited[start.x] = true;
    dist[start.dis] = 0;

    while(!q.empty())
    {
        p cur = q.front();
        q.pop();

        for(int i=0;i<myGraph[cur.x].size();i++)
        {
            int next = myGraph[cur.x][i];

            if(!visited[next])
            {
                q.push(make_p(next, cur.dis+1));
                visited[next]=true;
                dist[next] = cur.dis + 1;
            }
        }
    }

}

int main()
{
    cin>>N>>M;

    for(int i=0;i<M;i++)
    {
        int a, b;
        cin>>a>>b;

        myGraph[a].push_back(b);
        myGraph[b].push_back(a);
    }

    memset(kevin, 0, sizeof(kevin));

    for(int i=1;i<=N;i++)
    {
        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        bfs(make_p(i, 0));
        for(int j=1;j<=N;j++)
        {
            //cout<<dist[j]<<" ";
            kevin[i]+=dist[j];
        }
        //cout<<endl;
    }

    int kevin_baken=141006540;
    int answer=0;

    for(int i=1;i<=N;i++)
    {
        //cout<<kevin[i]<<endl;
        if(kevin[i]<kevin_baken)
        {
            kevin_baken=kevin[i];
            answer=i;
        } 
    }

    cout<<answer<<endl;


}