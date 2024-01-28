#include <iostream>
#include <math.h>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
  FASTIO();
  int N;
  cin >> N;

  vector<int> v;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    v.push_back(x);
  }

  int f = 0;
  int b = v.size() - 1;

  pair<int, int> p;
  int min = 2000000000;

  while (f < b) {
    if (abs(v[f] + v[b]) < min) {
      min = abs(v[f] + v[b]);
      p = {v[f], v[b]};
    }

    if (abs(v[f] + v[b - 1]) < abs(v[b] + v[f + 1])) {
      b -= 1;
    } else {
      f += 1;
    }
  }

  // cout << min << "\n";
  cout << p.first << " " << p.second << "\n";
}
