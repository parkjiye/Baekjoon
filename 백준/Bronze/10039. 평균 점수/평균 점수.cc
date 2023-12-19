#include <iostream>
using namespace std;

int main(){
    int total = 0, tmp;
    for(int i = 0; i < 5; i++){
        cin>>tmp;
        if(tmp < 40){
            tmp = 40;
        }
        total += tmp;
    }
    cout<<total/5;
    return 0;
}