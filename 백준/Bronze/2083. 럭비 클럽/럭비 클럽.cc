#include <iostream>

using namespace std;

int main() {
    string n;
    int age, weight;
    while (1) {
        cin >> n >> age >> weight;
        if (n == "#" && age == 0 && weight == 0) break;
        if (age > 17 || weight >= 80) cout << n << " Senior\n";
        else cout << n << " Junior\n";
    }
    return 0;
}