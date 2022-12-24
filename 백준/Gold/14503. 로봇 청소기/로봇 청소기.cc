#include<iostream>
#include<queue>

using namespace std;

int N, M;
int cnt;
int myMap[50][50];
bool visited[50][50];

bool flag=false;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

struct p
{
    int x;
    int y;
    int dir;
};

p make_p(int x, int y, int dir)
{
    p temp;
    temp.x = x;
    temp.y = y;
    temp.dir = dir;
    return temp;
};

int dfs(p start)
{
    if(flag) return 0;

    int blocked=0;
    for(int k=0;k<4;k++)
    {
        int next_x = start.x + dx[(start.dir+1+k)%4];
        int next_y = start.y + dy[(start.dir+1+k)%4];

        if(next_x>=0 && next_x<N && next_y>=0 && next_y<M && myMap[next_x][next_y]==0 && visited[next_x][next_y]==false)
        {
            visited[next_x][next_y]=true;
            cnt+=1;
            //cout<<next_x<<" "<<next_y<<endl;
            dfs(make_p(next_x, next_y, (start.dir+1+k)%4));
            if(flag) return 0;
        }
        else
        {
            blocked+=1;
        }
    }

    if(blocked==4)
    {
        int next_x;
        int next_y;

        if(start.dir==0 || start.dir ==2)
        {
            next_x = start.x + dx[start.dir]*(-1);
            next_y = start.y;
        }
        else if(start.dir==1 || start.dir==3)
        {
            next_x = start.x;
            next_y = start.y + dy[start.dir]*(-1);
        }

        //cout<<"blocked: "<<next_x<<" "<<next_y<<endl;

        if(next_x>=0 && next_x<N && next_y>=0 && next_y<M && myMap[next_x][next_y]==0)
        {
            dfs(make_p(next_x, next_y,start.dir));
        }
        else
        {
            flag = true;
        }
    }

    return 0;
}   

int main()
{
    cin>>N>>M;

    int pos_x;
    int pos_y;
    int dir;

    cin>>pos_x>>pos_y>>dir;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>myMap[i][j];
        }
    }

    cnt=1;
    visited[pos_x][pos_y]=true;

    if(dir==1) dir = 3;
    else if(dir==3) dir=1;

    dfs(make_p(pos_x, pos_y, dir));

    cout<<cnt<<endl;

}