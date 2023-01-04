#include<iostream>
#include<queue>
#include<string.h>

using namespace std;


int N;
char myMap[100][100];
bool visited[100][100];

int dx[4]={0, 0, -1, 1};
int dy[4]={1, -1, 0, 0};

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
    visited[start.x][start.y] = true;

    while(!q.empty())
    {
        p cur = q.front();
        q.pop();

        for(int k=0;k<4;k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if(next_x>=0 && next_x<N && next_y>=0 && next_y<N && !visited[next_x][next_y] && myMap[next_x][next_y]==myMap[cur.x][cur.y])
            {
                q.push(make_p(next_x, next_y));
                visited[next_x][next_y] = true;
            }
        }
    }

}

int main()
{
    cin>>N;

    for(int i=0;i<N;i++)
    {
        string sen;
        cin>>sen;

        for(int j=0;j<N;j++)
        {
            myMap[i][j]=sen[j];
        }
    }

    char arr[3]={'R', 'G', 'B'};
    
    int normal_ans=0;
    int not_ans=0;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!visited[i][j]) {
                bfs(make_p(i, j));
                normal_ans+=1;
            }
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(myMap[i][j]=='R' || myMap[i][j]=='G') {
                myMap[i][j]='P';
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!visited[i][j]) {
                bfs(make_p(i, j));
                not_ans+=1;
            }
        }
    }



    cout<<normal_ans<<" "<<not_ans<<endl;
}