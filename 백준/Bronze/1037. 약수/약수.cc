#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> pq;
    
    int N;
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;
        
        pq.push(x);
    }
    
    int front=pq.top();
    int back;
    
    while(!pq.empty())
    {
        back = pq.top();
        pq.pop();
    }
    
    cout<<front*back<<endl;
}