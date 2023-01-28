#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    vector<int> vec;

    int N;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        vec.push_back(i+1);
    }

    do{
        for(int a:vec)
            cout<<a<<" ";
        cout<<"\n";
    } while(next_permutation(vec.begin(), vec.end()));

}