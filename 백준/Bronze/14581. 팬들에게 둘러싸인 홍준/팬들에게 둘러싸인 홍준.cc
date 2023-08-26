#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	cin >> str;

	string fan = ":fan:";

	cout << fan << fan << fan<<"\n";
	cout << fan << ":" << str << ":" << fan << "\n";
	cout << fan << fan << fan;

}