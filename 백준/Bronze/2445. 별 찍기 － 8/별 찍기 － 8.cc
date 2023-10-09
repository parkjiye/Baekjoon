#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		for (int j = i; j > 0; j--) {
			cout << "*";
		}

		for (int k = 2 * (n - i); k > 0; k--) {
			cout << " ";
		}

		for (int l = i; l > 0; l--) {
			cout << "*";
		}

		cout << endl;
	}

	for (int i = n - 1; i > 0; i--) {

		for (int j = i; j > 0; j--) {
			cout << "*";
		}

		for (int k = 2 * (n - i); k > 0; k--) {
			cout << " ";
		}

		for (int l = i; l > 0; l--) {
			cout << "*";
		}

		cout << endl;
	}

}