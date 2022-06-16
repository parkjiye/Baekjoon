#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int count;
    cin>>count;

    int number;

    stack<int> stk;

    for(int i=0;i<count;i++)
    {
        cin>>number;

        if(number==0)
        {
            stk.pop();
        }
        else
        {
            stk.push(number);
        }
    }

    int sum=0;

    while(!stk.empty())
    {
        sum+=stk.top();
        stk.pop();
    }

    cout<<sum<<endl;
}