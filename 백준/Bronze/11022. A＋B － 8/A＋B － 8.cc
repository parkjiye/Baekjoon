#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        //Case #1: 1 + 1 = 2
        int a, b;
        cin>>a>>b;
        
        cout<<"Case #"<<i+1<<": "<<a<<" + "<<b<<" = "<<a+b<<endl;
    }
    
    return 0;
    
}