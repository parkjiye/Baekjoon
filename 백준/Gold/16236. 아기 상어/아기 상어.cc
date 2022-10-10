#include<iostream>
#include<queue>
#include<string.h>

const int MAX=25;
int myMap[MAX][MAX];
int n, currentLevel;
int curY, curX;
int nowfish=0;

int dx[4]={-1, 0, 0, 1};
int dy[4]={0, -1, 1, 0};

bool check[MAX][MAX];
int dist[MAX][MAX];

int second=0;

using namespace std;

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

bool isOkay(int y, int x)
{
    if(0<=y && y< n && 0<=x && x<n){
        if(check[y][x]) return false;
        if(myMap[y][x] ==0 || myMap[y][x] <= currentLevel) return true;
        else return false;
    }
    else return false;
}

void BFS()
{

    //queue에 curY, curX를 push
    queue<p> q;
    q.push(make_p(curX, curY));
    check[curY][curX] = true;
    dist[curY][curX] = 0;

    while(!q.empty())
    {
        p current = q.front();
        q.pop();

        for(int k=0;k<4;k++)
        {
            int next_y = current.y+dy[k];
            int next_x = current.x+dx[k];

            if(isOkay(next_y, next_x))
            {
                q.push(make_p(next_x, next_y));
                check[next_y][next_x]=true;
                dist[next_y][next_x]=dist[current.y][current.x]+1;
            }
        }
    }
}


bool callMom()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(myMap[i][j]<currentLevel && myMap[i][j]!=0 && myMap[i][j]!=9) return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    currentLevel = 2;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>myMap[i][j];

            if(myMap[i][j]==9)
            {
                curY=i;
                curX=j;
                myMap[i][j]=0;
            }
        }
    }

    while(1)
    {
        memset(check, 0, sizeof(check));
        memset(dist, 0, sizeof(dist));

        BFS();

        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<myMap[i][j];
            }
            cout<<"\n";
        }*/
        int minDist = 987987987;
        int minx;
        int miny;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                    if(check[i][j] && myMap[i][j]!=0 && myMap[i][j]<currentLevel)
                    {
                        if(minDist > dist[i][j])
                        {
                            minDist = dist[i][j];
                            minx=j;
                            miny=i;
                        }
                    }
                }
            }

        if(minDist==987987987) break;
        second+=dist[miny][minx];
        myMap[miny][minx]=0;

        curX=minx;
        curY=miny;
        
        nowfish++;

        if(nowfish==currentLevel)
        {
            currentLevel++;
            nowfish=0;
        }   
        
    }

    cout<<second<<endl;

}