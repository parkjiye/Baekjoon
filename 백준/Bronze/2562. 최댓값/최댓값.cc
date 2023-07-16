#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    vector<int> v;
    for(int i=0;i<9;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    
    cout<<*max_element(v.begin(), v.end())<<endl;
    cout<<max_element(v.begin(), v.end())-v.begin()+1<<endl;
}