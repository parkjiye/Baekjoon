#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

int myMap[50][50];
int T;
int M, N, K;
bool visited[50][50];
int dx[4]={0, 0, 1, -1};
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
    visited[start.x][start.y]=true;

    while(!q.empty())
    {
        p cur = q.front();
        q.pop();

        for(int k=0;k<4;k++)
        {
            int next_x = cur.x+dx[k];
            int next_y = cur.y+dy[k];

            if(next_x>=0 && next_x<N && next_y>=0 && next_y<M && !visited[next_x][next_y] && myMap[next_x][next_y]==1)
            {
                q.push(make_p(next_x, next_y));
                visited[next_x][next_y]=true;
            }
        }
    }
}

int main()
{
    cin>>T;
    int answer;

    for(int test_case=1;test_case<=T;test_case++)
    {
        answer=0;

        memset(myMap, 0, sizeof(myMap));
        memset(visited, 0, sizeof(visited));

        cin>>M>>N>>K;

        for(int i=0;i<K;i++)
        {
            int x, y;
            cin>>y>>x;

            myMap[x][y]=1;
        }

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(myMap[i][j]==1 && !visited[i][j])
                {
                    bfs(make_p(i, j));
                    answer+=1;
                }
            }
        }

        cout<<answer<<endl;

    }
}