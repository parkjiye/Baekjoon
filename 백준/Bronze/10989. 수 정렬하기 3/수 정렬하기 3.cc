#include <iostream>
#include <map>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
  FASTIO();
  int N;
  cin >> N;
  map<int, int> m;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    if (m.find(x) != m.end()) {
      m[x] += 1;
    } else {
      m.insert({x, 1});
    }
  }

  for (auto it = m.begin(); it != m.end(); it++) {
    int cur = it->first;
    int cnt = it->second;

    for (int i = 0; i < cnt; i++) {
      cout << cur << "\n";
    }
  }
}
