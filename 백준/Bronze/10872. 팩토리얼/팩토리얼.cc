#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    
    if(N==0)
    {
        cout<<1<<endl;
        return 0;
    }
    
    int answer=1;
    
    for(int i=1;i<=N;i++)
    {
        answer*=i;
    }
    
    cout<<answer<<endl;
}