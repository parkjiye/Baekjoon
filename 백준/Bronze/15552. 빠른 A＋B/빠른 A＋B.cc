#include<iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO();
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++)
    {
        int a, b;
        cin>>a>>b;
        
        cout<<a+b<<"\n";
    }
}