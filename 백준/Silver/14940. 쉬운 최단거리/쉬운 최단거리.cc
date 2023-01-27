#include<iostream>
#include<queue>

using namespace std;

int n, m;
int myMap[1000][1000];
int dis[1000][1000];
bool visited[1000][1000];

int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};

struct p
{
    int x;
    int y;
};

p make_p(int x, int y)
{
    p temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

void bfs(p start)
{
    queue<p> q;
    q.push(start);
    visited[start.x][start.y]=true;
    dis[start.x][start.y]=0;

    while(!q.empty())
    {
        p cur = q.front();
        q.pop();

        for(int k=0;k<4;k++)
        {
            int next_x = cur.x+dx[k];
            int next_y = cur.y+dy[k];

            if(next_x>=0 && next_x<n && next_y>=0 && next_y<m && myMap[next_x][next_y]!=0 && !visited[next_x][next_y])
            {
                q.push(make_p(next_x, next_y));
                visited[next_x][next_y]=true;
                dis[next_x][next_y]=dis[cur.x][cur.y]+1;
            }
        }
    }
}

int main()
{
    cin>>n>>m;

    p start;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int num;
            cin>>num;

            myMap[i][j]=num;

            if(num==2) start = make_p(i, j);
        }
    }

    bfs(start);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dis[i][j]==0 && myMap[i][j]==1)
            {
                cout<<"-1 ";
            }
            else
            {
                cout<<dis[i][j]<<" ";
            }
        }
        cout<<endl;
    }


}