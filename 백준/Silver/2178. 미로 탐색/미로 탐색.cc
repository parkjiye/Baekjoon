#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, m;

int myMap[101][101];
int dist[101][101];
bool check[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

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

void bfs()
{
    queue<p> q;
    q.push(make_p(0, 0));
    memset(dist, 0, sizeof(dist));
    memset(check, 0, sizeof(check));

    dist[0][0] = 1;
    check[0][0] = true;

    while (!q.empty())
    {
        if(dist[n-1][m-1]!=0) break;
        p cur = q.front();
        q.pop();

        int cur_x = cur.x;
        int cur_y = cur.y;

        //check[cur.y][cur.x] = true;

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur_x + dx[k];
            int next_y = cur_y + dy[k];
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n)
            {
                if (!check[next_y][next_x] && myMap[next_y][next_x] == 1)
                {
                    q.push(make_p(next_x, next_y));
                    dist[next_y][next_x] = dist[cur_y][cur_x]+1;
                    check[next_y][next_x] = true;
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;

    for (int i = 0; i < n; i++)
    {
        string row;
        cin>>row;
        for (int j = 0; j < m; j++)
        {
            myMap[i][j]=row[j]-'0';
        }
    }

    bfs();

    if(dist[n-1][m-1]!=0) cout<<dist[n-1][m-1]<<endl;
    return 0; 
}