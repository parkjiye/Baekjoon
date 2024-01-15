#include <algorithm>
#include <iostream>
#include <vector>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, K;
vector<int> height;
vector<int> gap;

int main() {
  FASTIO();
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    height.push_back(x);
  }

  for (int i = 0; i < N - 1; i++) {
    gap.push_back(height[i + 1] - height[i]);
  }

  sort(gap.begin(), gap.end());

  long answer = 0;
  for (int i = 0; i < N - K; i++) {
    answer += gap[i];
  }

  cout << answer << "\n";
}
