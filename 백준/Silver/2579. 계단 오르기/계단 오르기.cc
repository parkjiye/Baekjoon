#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr; 
vector<int> sum;

int main()
{

    int length;
    cin>>length;

    for(int i=0;i<length;i++)
    {
        int num;
        cin>>num;
        arr.push_back(num);
    }

    sum.push_back(arr[0]);
    sum.push_back(arr[0]+arr[1]);
    sum.push_back(max(arr[0], arr[1])+arr[2]);

    for(int i=3;i<length;i++)
    {
        sum.push_back(max(sum[i-3]+arr[i-1]+arr[i], sum[i-2]+arr[i]));
    }

    cout<<sum[length-1]<<endl;
    
}