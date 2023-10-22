#include <iostream>

using namespace std;

int main() {

	int t;
	string s;

	cin >> t >> s;
	
	int sum = 0;

	for (int i = 0; i < t; i++) {
		sum += s[i] - '0';
	}

	cout << sum;


	return 0;
}