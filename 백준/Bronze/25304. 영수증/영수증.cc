#include <iostream>

using namespace std;

int main()
{
    int total;
    cin>>total;
    
    int N;
    cin>>N;
    
    int sum=0;
    
    for(int i=0;i<N;i++)
    {
        int price, cnt;
        cin>>price>>cnt;
        sum += (price*cnt);
    }
    
    if(sum==total)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}