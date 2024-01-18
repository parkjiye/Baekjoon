#include <iostream>
#include <string.h>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

bool isPrime[1005];

int main() {
  int N;
  cin >> N;
  memset(isPrime, 0, sizeof(isPrime));
  isPrime[1] = true;

  for (int i = 2; i <= 1000; i++) {
    if (!isPrime[i]) {
      int j = 2;
      while (i * j <= 1000) {
        isPrime[i * j] = true;
        j += 1;
      }
    }
  }

  int answer = 0;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    if (!isPrime[x]) {
      answer += 1;
    }
  }

  cout << answer << "\n";
}
