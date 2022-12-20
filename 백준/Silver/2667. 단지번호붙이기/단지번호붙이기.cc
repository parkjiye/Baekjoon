#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;


int N;
int myMap[25][25];
bool visited[25][25];

int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

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

int bfs(p start)
{
    queue<p> q;

    int home=0;

    q.push(start);
    home+=1;
    visited[start.y][start.x] = true;

    while(!q.empty())
    {
        p cur = q.front();
        q.pop();

        for(int k=0;k<4;k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if(next_x>=0 && next_x<N && next_y>=0 && next_y<N && myMap[next_y][next_x]==1 && visited[next_y][next_x]==false)
            {
                home+=1;
                q.push(make_p(next_x, next_y));
                visited[next_y][next_x]=true;
            }
        }
    }

    return home;
    
}

int main()
{
    cin>>N;

    for(int i=0;i<N;i++)
    {
        string line;
        cin>>line;

        for(int j=0;j<N;j++)
        {
            myMap[i][j] = line[j]-'0';
        }
    }

    int answer=0;
    vector<int> homes;

    memset(visited, 0, sizeof(visited));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(myMap[i][j]==1 && visited[i][j]==false) {
                homes.push_back(bfs(make_p(j, i)));
                answer+=1;
            }

        }
    }

    cout<<answer<<endl;

    sort(homes.begin(), homes.end());

    for(int i=0;i<answer;i++)
    {
        cout<<homes[i]<<endl;
    }


}