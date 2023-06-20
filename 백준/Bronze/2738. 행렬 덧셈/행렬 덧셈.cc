#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;
    
    int arr[105][105];
    memset(arr, 0, sizeof(arr));
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int x;
            cin>>x;
            
            arr[i][j]+=x;
        }
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int x;
            cin>>x;
            
            arr[i][j]+=x;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}