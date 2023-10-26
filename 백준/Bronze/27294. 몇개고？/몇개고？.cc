#include <iostream>

using namespace std;

int main() {
    
    int T, S;
    
    cin >> T >> S;
    
    if(S == 0 && (12 <= T && T <= 16))
        cout << "320";
    else
        cout << "280";
    return 0;
}