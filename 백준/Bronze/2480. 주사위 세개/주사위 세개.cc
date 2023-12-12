#include <iostream>
#include <algorithm>
using namespace std;
 
int main(int argc, char const *argv[]) {
 
	ios_base::sync_with_stdio(false);
 
	int a, b, c;
	cin >> a >> b >> c;
 
    if (a != b && b != c && a != c) {
		int m;
		m = max({a, b, c});
		cout << m * 100;
	}
	else if (a == b && a == c) {
		cout << 10000 + a * 1000;
	}
	else if (a == b || a == c) {
		cout << 1000 + a * 100;
	}
	else {
		cout << 1000 + b * 100;
	}
	return 0;
}