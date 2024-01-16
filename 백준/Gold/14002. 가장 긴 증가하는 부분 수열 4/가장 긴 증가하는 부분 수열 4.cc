#include <algorithm>
#include <deque>
#include <iostream>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int dp[1005];
int num[1005];
deque<int> dq;

int main() {
  FASTIO();
  cin >> N;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    dp[i] = 1;
    num[i] = x;
  }

  int cnt = 1;

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (num[i] > num[j]) {
        dp[i] = max(dp[j] + 1, dp[i]);
      }
    }

    if (dp[i] > cnt) {
      cnt = dp[i];
    }
  }

  cout << cnt << "\n";

  for (int i = N - 1; i >= 0; i--) {
    if (dp[i] == cnt) {
      dq.push_front(num[i]);
      cnt -= 1;
    }
  }

  while (!dq.empty()) {
    cout << dq.front() << " ";
    dq.pop_front();
  }
  cout << "\n";
  return 0;
}
