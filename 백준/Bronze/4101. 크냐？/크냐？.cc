#include <iostream>

using namespace std;

int main()
{
    int N, M;
    
    while(1)
    {
        cin>>N>>M;
        
        if(N==0 &&M==0)
        {
            break;
        }
        
        if(N>M)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    
    
}