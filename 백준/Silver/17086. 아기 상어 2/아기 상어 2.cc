#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int N, M;
int myMap[50][50];
int mydis[50][50];
bool visited[50][50];

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

queue<p> q;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs()
{
    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 8; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if(next_x>=0 && next_x<N && next_y>=0 && next_y<M && !visited[next_x][next_y])
            {
                if(mydis[cur.x][cur.y]+1<mydis[next_x][next_y])
                {
                    mydis[next_x][next_y]=mydis[cur.x][cur.y]+1;
                    visited[next_x][next_y]=true;
                    q.push(make_p(next_x, next_y));
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            mydis[i][j]=10000000;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num;
            cin >> num;

            if (num == 1)
            {
                q.push(make_p(i, j));
                visited[i][j]=true;
                mydis[i][j]=0;
            }
        }
    }

    bfs();

    int answer=0;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(mydis[i][j]>answer)
            {
                answer=mydis[i][j];
            }
        }
    }

    cout<<answer<<endl;
}