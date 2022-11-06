#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> music;

    bool ascending=false;
    bool descending=false;

    for(int i=0;i<8;i++)
    {
        int x;
        cin>>x;
        music.push_back(x);
    }

    for(int i=0;i<7;i++)
    {
        if(music[i]<music[i+1])
        {
            if(!descending) ascending=true;
            else
            {
                descending=false;
                break;
            }
        }
        else
        {
            if(!ascending) descending=true;
            else
            {
                ascending=false;
                break;
            }
        }
    }

    if(ascending==false && descending==false) cout<<"mixed"<<endl;
    else if(ascending==true) cout<<"ascending"<<endl;
    else cout<<"descending"<<endl;

}