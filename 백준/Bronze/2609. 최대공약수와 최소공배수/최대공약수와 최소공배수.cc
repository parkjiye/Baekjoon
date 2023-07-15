#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    
    int gc = gcd(n, m);
    cout<<gc<<endl;
    cout<<n*m/gc<<endl;
}