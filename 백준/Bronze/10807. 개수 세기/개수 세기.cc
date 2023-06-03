#include<iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    
    int arr[105];
    
    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;
        arr[i]=x;
    }
    
    int num;
    cin>>num;
    
    int cnt=0;
    
    for(int i=0;i<N;i++)
    {
        if(arr[i]==num)
        {
            cnt+=1;
        }
    }
    
    cout<<cnt<<endl;
    return 0;
}