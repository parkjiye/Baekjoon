#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int count;
    cin>>count;

    string cmd;
    int data;

    stack<int> stk;

    for(int i=0;i<count;i++)
    {
        cin>>cmd;

        if(cmd=="push")
        {
            cin>>data;
            stk.push(data);
        }
        else if(cmd=="pop")
        {
            if(stk.empty())
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<stk.top()<<endl;
                stk.pop();
            }
        }
        else if(cmd=="size")
        {
            cout<<stk.size()<<endl;
        }
        else if(cmd=="empty")
        {
            if(stk.empty())
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
        }
        else if(cmd=="top")
        {
            if(stk.empty())
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<stk.top()<<endl;
            }
        }

    }
}