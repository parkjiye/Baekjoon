#include<iostream>
#include<queue>
#include<string.h>
#include<vector>

using namespace std;

int m,n;
int myMap[1000][1000];
int ripe_tomato=0;
int notripe_tomato=0;

struct p
{
    int x;
    int y;
};

queue<p> q;

p make_p(int x, int y)
{
    p temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void bfs()
{
    while(!q.empty())
    {
        p cur = q.front();
        q.pop();

        for(int k=0;k<4;k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if(next_x>=0 && next_x<m && next_y>=0 && next_y<n && myMap[next_x][next_y]==0)
            {
                q.push(make_p(next_x, next_y));
                myMap[next_x][next_y]=myMap[cur.x][cur.y]+1;
            }
        }
    }


}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>myMap[i][j];
            if(myMap[i][j]==1) {
                ripe_tomato+=1;
                q.push(make_p(i, j));
                //ripe.push_back(make_p(i, j));
            }
            else if(myMap[i][j]==0)
            {
                notripe_tomato+=1;
            }
        }
    }

    if(notripe_tomato==0)
    {
        cout<<0<<endl;
        return 0;
    }

    bfs();

    int answer=-1;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(myMap[i][j]==0)
            {
                cout<<-1<<endl;
                return 0;
            }
            if(myMap[i][j]>answer)
            {
                answer=myMap[i][j];
            }
        }
    }

    cout<<answer-1<<endl;
    return 0;

        
}