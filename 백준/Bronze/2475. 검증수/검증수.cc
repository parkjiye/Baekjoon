#include<iostream>

using namespace std;

int main()
{
    int ans=0;
    
    for(int i=0;i<5;i++)
    {
        int x;
        cin>>x;
        ans+=x*x;
    }
    
    cout<<ans%10<<endl;
}