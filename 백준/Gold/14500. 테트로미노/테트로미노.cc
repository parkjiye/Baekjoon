#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
int myMap[500][500];
bool visited[500][500];

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

int total;
int answer;

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

int dfs(p start, int depth, int sum)
{
    if(depth == 3)
    {
        answer = max(answer, sum);
        return 0;
    }
    else
    {
        for(int k=0;k<4;k++)
        {
            int next_x = start.x + dx[k];
            int next_y = start.y + dy[k];

            if(next_x>=0 && next_x<N && next_y>=0 && next_y<M && !visited[next_x][next_y])
            {
                visited[next_x][next_y]=true;
                dfs(make_p(next_x, next_y), depth+1, sum+myMap[next_x][next_y]);
                visited[next_x][next_y]=false;
            }
        }

        return 0;
    }
}

int main()
{
    cin>>N>>M;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int num;
            cin>>num;
            myMap[i][j]=num;
        }
    }
    answer=0;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            visited[i][j]=true;
            dfs(make_p(i, j), 0, myMap[i][j]);
            visited[i][j]=false;

            if(i==0 && j>0 && j<M-1)
            {
                answer=max(myMap[i][j-1]+myMap[i][j]+myMap[i][j+1]+myMap[i+1][j], answer);
            }
            else if(i==N-1 && j>0 && j<M-1)
            {
                answer=max(myMap[i][j-1]+myMap[i][j]+myMap[i][j+1]+myMap[i-1][j], answer);
            }
            else if(j==0 && i>0 && i<N-1)
            {
                answer=max(myMap[i-1][j]+myMap[i][j]+myMap[i+1][j]+myMap[i][j+1], answer);
            }
            else if(j==N-1 && i>0 && i<N-1)
            {
                answer=max(myMap[i-1][j]+myMap[i][j]+myMap[i+1][j]+myMap[i][j-1], answer);
            }
            else if(i>0 && i<N-1 && j>0 && j<M-1)
            {
                vector<int> sum;
                sum.push_back(myMap[i][j-1]+myMap[i][j]+myMap[i][j+1]+myMap[i+1][j]);
                sum.push_back(myMap[i][j-1]+myMap[i][j]+myMap[i][j+1]+myMap[i-1][j]);
                sum.push_back(myMap[i-1][j]+myMap[i][j]+myMap[i+1][j]+myMap[i][j+1]);
                sum.push_back(myMap[i-1][j]+myMap[i][j]+myMap[i+1][j]+myMap[i][j-1]);

                for(int i=0;i<4;i++)
                {
                    answer = max(answer, sum[i]);
                }
            
            }
        }
    }

    cout<<answer<<endl;

    
}