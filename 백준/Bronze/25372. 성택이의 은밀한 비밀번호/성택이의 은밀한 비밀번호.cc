#include<iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        string sen;
        cin>>sen;
    
        if(sen.length()>=6 && sen.length()<=9)
        {
            cout<<"yes"<<"\n";
        }
        else
        {
            cout<<"no"<<"\n";
        }
    }
}