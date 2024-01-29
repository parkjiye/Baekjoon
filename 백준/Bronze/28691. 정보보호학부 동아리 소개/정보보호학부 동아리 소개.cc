#include <iostream>
#include <map>

using namespace std;

int main() {

  map<char, string> clubMap = {
    {'M', "MatKor"},
    {'W', "WiCys"},
    {'C', "CyKor"},
    {'A', "AlKor"},
    {'$', "$clear"}
  };

  char firstLetter; cin >> firstLetter;

  cout << clubMap[firstLetter] << "\n";

  return 0;
}