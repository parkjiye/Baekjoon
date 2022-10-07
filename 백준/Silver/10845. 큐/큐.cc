#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int count;
    cin>>count;

    string cmd;
    int num;
    int front;

    queue<int> que;

    for(int i=0;i<count;i++)
    {
        cin>>cmd;
        if(cmd=="push")
        {
            cin>>num;
            que.push(num);
        }
        else if(cmd=="pop")
        {
            if(que.empty())
            {
                cout<<-1<<endl;
            }
            else
            {
                front=que.front();
                cout<<front<<endl;
                que.pop();
            }
        }
        else if(cmd=="size")
        {
            cout<<que.size()<<endl;
        }
        else if(cmd=="empty")
        {
            if(que.empty())
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
        }
        else if(cmd=="front")
        {
            if(que.empty())
            {
                cout<<-1<<endl;
            }
            else
            {
                front=que.front();
                cout<<front<<endl;
            }
        }
        else if(cmd=="back")
        {
            if(que.empty())
            {
                cout<<-1<<endl;
            }
            else
            {
                front=que.back();
                cout<<front<<endl;
            }
        }
    }
}