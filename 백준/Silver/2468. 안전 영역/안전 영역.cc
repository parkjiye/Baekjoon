#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

int myMap[100][100];
bool visited[100][100];
int N;

int minimum;
int maximum;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

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

void bfs(int depth, p start)
{
    queue<p> q;
    q.push(start);
    visited[start.x][start.y]=true;

    while(!q.empty())
    {
        p cur = q.front();
        q.pop();

        for(int k=0;k<4;k++)
        {
            int next_x = cur.x+dx[k];
            int next_y = cur.y+dy[k];

            if(next_x>=0 && next_x<N && next_y>=0 && next_y<N && !visited[next_x][next_y] && myMap[next_x][next_y]>depth)
            {
                q.push(make_p(next_x, next_y));
                visited[next_x][next_y]=true;
            }
        }
    }
}

int main()
{
    cin>>N;

    minimum=101;
    maximum=0;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int num;
            cin>>num;
            myMap[i][j]=num;

            if(num>maximum) maximum = num;
            if(num<minimum) minimum = num;
            
        }
    }

    //cout<<maximum<<" "<<minimum<<endl;

    int answer=1;

    for(int k=minimum;k<maximum;k++)
    {
        int depth = 0;
        memset(visited, 0, sizeof(visited));

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(!visited[i][j] && myMap[i][j]>k)
                {
                    bfs(k, make_p(i, j));
                    depth+=1;
                } 
            }
        }

        if(answer<depth) answer=depth;
    }

    cout<<answer<<endl;
}