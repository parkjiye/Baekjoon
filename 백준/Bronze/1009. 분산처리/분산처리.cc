#include <iostream>

using namespace std;

int main() {
	int t,a,b, mul;
    
	cin >> t;
    
	while(t--) {
		mul = 1;
		cin >> a >> b;
		b=!(b%4)?4:b%4;
		while (b--)mul *= a;
		cout << (mul%10?mul%10:10) << "\n";
	}
}