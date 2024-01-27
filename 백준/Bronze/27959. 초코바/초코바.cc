#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (n * 100 >= m)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}