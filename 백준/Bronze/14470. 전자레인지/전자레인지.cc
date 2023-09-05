#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int a, b, c, d, e;
    cin>>a>>b>>c>>d>>e;
    if (a < 0)
        cout<<abs(a)*c + d + b*e;
    else
        cout<<(b-a)*e;
    return 0;
}