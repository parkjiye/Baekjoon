#include<iostream>

using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;

    int i = 0;
    int o = 0;

    int answer=0;

    string sen;
    cin>>sen;

    for(int k=0;k<M;k++)
    {
        if(sen[k]=='O') o+=1;
        if(sen[k]=='I') i+=1;

        if(o>i)
        {
            i=0;
            o=0;
        }

        if(i>o+1)
        {
            i=1;
            o=0;
        }

        if(o==N && i==N+1)
        {
            answer+=1;
            i--;
            o--;
        }
    }

    cout<<answer<<endl;
}