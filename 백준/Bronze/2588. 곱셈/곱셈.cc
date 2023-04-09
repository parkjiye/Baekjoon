#include<iostream>

using namespace std;

int main()
{
    int x;
    int y;
    cin>>x>>y;
    
    int first = y/100;
    int second = (y-(first*100))/10;
    int third = (y-(first*100)-(second*10));
    
    cout<<x*third<<endl;
    cout<<x*second<<endl;
    cout<<x*first<<endl;
    cout<<x*y<<endl;
    
    return 0;
}