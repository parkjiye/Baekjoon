#include <iostream>

using namespace std;

int main() {
    int count;
    cin>>count;

    for (int i = 0; i < count ; i++)
   {
       for (int j = 0; j < i; j++)
            cout << " ";

        for (int j = 0; j < 2*(count-i)-1 ; j++)
            cout << "*";

        cout << endl;
   }
    
   for (int i = 0; i < count-1 ; i++)
   {
        for (int j = 0; j < count-i-2 ; j++)
            cout << " ";

        for (int j = 0; j < 2*(i+1)+1; j++)
            cout << "*";

        cout << endl;
   }   
    
}