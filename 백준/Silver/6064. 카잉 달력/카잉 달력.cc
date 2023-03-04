// x<M이면 x'=x+1 그렇지 않으면 x'=1
// y<N이면 y'=y+1 그렇지 않으면 y'=1
// <1:1> <2:2> <3:3> <4:4> <5:5> <6:6> ...<9:9> <10:10> 
// <1:11> <2:12> <3:1> <4:2> <5:3> <6:4> <7:5> <8:6> <9:7> <10:8>
// <1:9> <2:10> <3:11> <4:12> 
#include<iostream>

using namespace std;
int gcd(int x, int y){

    int temp;

    if(x<y){

        temp = x;

        x= y;

        y = temp;

    }

    int rest;

    while(y!=0){

        rest = x%y;

        x = y;

        y = rest;

    }

    return x;

}

int main()
{
    int test_cases;
    cin>>test_cases;

    for(int test_case=1;test_case<=test_cases;test_case++)
    {
        int M, N, x, y;

        cin>>M>>N>>x>>y;

        int answer=-1;

        int max = N*M/gcd(M,N);
        
        for(int i=x;i<=max;i+=M)
        {
            int temp_y = i%N;
            if(temp_y==0)
            {
                temp_y = N;
            }

            if(temp_y == y)
            {
                answer=i;
                break;
            }
            
        }

        cout<<answer<<endl;
    }
}