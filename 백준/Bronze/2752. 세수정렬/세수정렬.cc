#include <iostream>
using namespace std;

int main(){
    int numbers[3], tmp;
    for(int i = 0; i < 3; i++){
        cin>>numbers[i];
    }
    
    for(int i = 0; i < 3-1; i++){
        for(int j = i+1; j < 3; j++){
            if(numbers[i] > numbers[j]){
                tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }
        }
    }
    
    for(int i = 0; i < 3; i++){
        cout<<numbers[i]<<" ";
    }
    return 0;
}