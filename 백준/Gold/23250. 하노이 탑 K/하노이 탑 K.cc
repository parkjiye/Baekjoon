/*
1. 1<=N<=60
2. K번째 이동
*/

#include<iostream>
#include<math.h>

using namespace std;

int cnt;
int N;
unsigned long long int K;


int main()
{
    cin>>N>>K;

    unsigned long long int a=1;

    for(int i=0;i<N-1;i++)
    {
        a*=2;
    }
    
    unsigned long long int b=a/2;

    int from = 1;
    int to = 3;
    int by = 2;

    while(1)
    {
        if(K==a)
        {
            cout<<from<<" "<<to<<endl;
            return 0;
        }
        else if(K<a)
        {
            int temp = to;
            to = by;
            by = temp;
            a-=b;
        }
        else
        {
            int temp = from;
            from = by;
            by = temp;
            a+=b;
        }

        b/=2;
    }
    
}