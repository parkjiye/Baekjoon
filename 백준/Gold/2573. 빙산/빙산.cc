#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int N, M;
int myMap[300][300];
bool visited[300][300];
bool departed;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, 1, -1};

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

            if(next_x>=0 && next_x<N && next_y>=0 && next_y<M)
            {
                if(myMap[next_x][next_y]==0 && myMap[cur.x][cur.y]>0 && !visited[next_x][next_y]) myMap[cur.x][cur.y]--;
                if(myMap[next_x][next_y]!=0 && !visited[next_x][next_y])
                {
                    q.push(make_p(next_x, next_y));
                    visited[next_x][next_y]=true;
                    //cout<<next_x<<" "<<next_y<<endl;
                } 
            }
        }
    }

}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num;
            cin >> num;
            myMap[i][j] = num;
        }
    }

    int day=0;
    departed=false;

    while (!departed)
    {
        int island = 0;
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (myMap[i][j] != 0 && !visited[i][j])
                {
                    bfs(make_p(i, j));
                    island+=1;
                }
            }
        }

        // for(int i=0;i<N;i++)
        // {
        //     for(int j=0;j<M;j++)
        //     {

        //         cout<<myMap[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        //cout<<island<<endl;
        day+=1;

        if(island>1) departed = true;
        if(island==0)
        {
            cout<<0<<endl;
            return 0;
        }
    }

    cout<<day-1<<endl;
}