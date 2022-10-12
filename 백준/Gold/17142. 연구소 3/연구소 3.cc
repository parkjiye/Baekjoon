#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

int myMap[51][51];
int Table[51][51];
bool check[51][51];

int arr[51*51];

struct p {
    int x;
    int y;
};

p make_p(int y, int x) {
    p temp;

    temp.x = x;
    temp.y = y;

    return temp;
}

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

p diff[11];
int diff_len=0;

using namespace std;

vector<int> list;

int n, m;

void BFS(p start)
{
    queue<p> Queue;
    
    memset(check, 0, sizeof(check));

    Queue.push(make_p(start.y, start.x));
    check[start.y][start.x] = true;
    Table[start.y][start.x] = 0;

    while(!Queue.empty()) {
        p current = Queue.front();
        Queue.pop();

        for(int k=0;k<4;k++) {
            int next_y = current.y+dy[k];
            int next_x = current.x+dx[k];

            if(0<=next_y && next_y<n && 0<=next_x && next_x<n && !check[next_y][next_x] && myMap[next_y][next_x]!=1 && Table[next_y][next_x] > Table[current.y][current.x]+1)
            {
                Queue.push(make_p(next_y, next_x));
                check[next_y][next_x] = true;
                Table[next_y][next_x] = Table[current.y][current.x] + 1;
            }
        }
    }

}

int pathlist()
{
    int result = 0;

    for(int i=0; i<n;i++) {
        for(int j=0; j<n;j++) {
            if(Table[i][j]==987987987)
            {
                if(myMap[i][j]!=1)
                {
                        list.push_back(-1);
                        return 0;
                }
            }
            else
            {
                if(myMap[i][j]!=2)
                {
                    result = max(result, Table[i][j]);
                }
            }
        }
    }
   

    list.push_back(result);
    return 0;
}


void getResult(int inx)
{
    //지금 inx번째의 for문이다
    //inx번째 for문의 변수 값을 지정해줘야함

    if(inx >= m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                Table[i][j]=987987987;
            }
        }

        p test_diff[m];
        for(int i=0;i<m;i++)
        {
            test_diff[i].y=diff[arr[i]].y;
            test_diff[i].x=diff[arr[i]].x;
        }

        for(int i=0;i<m;i++)
        {
            //cout<<test_diff[i].x<<test_diff[i].y<<endl;
            BFS(test_diff[i]);
        }

        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(Table[i][j]==987987987) cout<<"-";
                else cout<<Table[i][j];
            }
            cout<<endl;
        }*/

        pathlist();

    }
    else
    {
        for(int i=0;i<diff_len;i++)
        {
            if(inx==0 || arr[inx-1]<i){
                arr[inx]=i;
                getResult(inx+1);
            }
        }
    }
}

//getResult(0) -> arr[0]=0 -> getResult(1) -> arr[1]=1 ->getResult(2) -> arr[2]=2
//arr[0]=0 arr[1]=1 

int main()
{
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>myMap[i][j];

            if(myMap[i][j]==2)
            {
                diff[diff_len].y=i;
                diff[diff_len].x=j;

                diff_len++;
            }
        }
    }
    getResult(0);

    int answer=987987987;

    for(int i=0;i<list.size();i++)
    {
        //cout<<list[i]<<" ";
        if(list[i]!=-1 && answer>list[i]) answer=list[i];
    }

    if(answer==987987987) cout<<"-1"<<endl;
    else cout<<answer<<endl;
}