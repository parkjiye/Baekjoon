#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int count;
    cin>>count;

    float largest_idx=0;
    int largest=0;

    vector<float> score;

    for(int i=0;i<count;i++)
    {
        float num;
        cin>>num;
        score.push_back(num);

        if(largest<num)
        {
            largest=num;
            largest_idx=i;
        }
    }
    //cout<<largest<<endl;

    float sum=0;

    for(int i=0;i<count;i++)
    {
        score[i] = score[i]/largest*100;
    }

    for(int i=0;i<count;i++)
    {
        //cout<<score[i]<<endl;
        sum+=score[i];
    }

    cout<<sum/count<<endl;
}