#include <iostream>

using namespace std;

int N, M, K;
int answer;
char myMap[6][6];
bool visited[6][6];

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

int dfs(p start, int dist)
{
    visited[start.x][start.y]=true;
    if (dist == K && start.x==0 && start.y==M-1)
    {
        //cout<<"found path"<<endl;
        answer += 1;
        return 0;
    }
    else if(dist == K)
    {
        //cout<<"no path"<<endl;
        return 0;
    }
    else
    {
        for (int k = 0; k < 4; k++)
        {
            int next_x = start.x + dx[k];
            int next_y = start.y + dy[k];

            if(next_x>=0 && next_x<N && next_y>=0 && next_y<M && myMap[next_x][next_y]!='T' && !visited[next_x][next_y])
            {
                visited[next_x][next_y]=true;
                //cout<<next_x<<" "<<next_y<<endl;
                dfs(make_p(next_x, next_y), dist+1);
                visited[next_x][next_y]=false;
            }
        }
    }
    return 0;
}

int main()
{
    cin >> N >> M >> K;
    
    answer=0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char num;
            cin >> num;
            myMap[i][j] = num;
        }
    }

    dfs(make_p(N-1, 0), 1);

    cout<<answer<<endl;
}