#include <iostream>
using namespace std;
int main() {
    int n, w, h, l;
    cin >> n >> w >> h >> l;
    int ans = (w / l) * (h / l);
    n < ans ? cout << n : cout << ans;
    return 0;
}