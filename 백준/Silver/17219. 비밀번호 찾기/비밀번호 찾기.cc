#include<iostream>
#include<map>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M;
    cin>>N>>M;

    map<string, string> s;

    for(int i=0;i<N;i++)
    {
        string site;
        string pw;

        cin>>site>>pw;

        s[site] = pw;
    }

    for(int i=0;i<M;i++)
    {
        string site;
        cin>>site;
        cout<<s[site]<<"\n";
    }
}