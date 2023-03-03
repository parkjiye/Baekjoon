#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int num, total;
    cin>>num>>total;

    int answer=0;

    stack<int> s;

    for(int i=0;i<num;i++)
    {
        int x;
        cin>>x;
        s.push(x);
    }

    while(!s.empty())
    {
        if(total==0) break;

        int cur = s.top();
        s.pop();

        if(cur>total) continue;
        else
        {
            answer+=total/cur;
            total = total - total/cur * cur;
        }
    }

    cout<<answer<<endl;


}