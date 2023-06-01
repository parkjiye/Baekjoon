#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        string sen;
        cin>>sen;
        
        if(sen.length()==1)
        {
            cout<<sen[0]<<sen[0]<<endl;
        }
        else
        {
            cout<<sen[0]<<sen[sen.length()-1]<<endl;
        }
    }
}