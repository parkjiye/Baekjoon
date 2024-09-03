#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    
    vector<set<int>> dp(9); // dp[i]는 N을 i번 사용해서 만들 수 있는 모든 숫자 집합
    
    for (int i = 1; i <= 8; ++i) {
        dp[i].insert(stoi(string(i, N + '0'))); // N, NN, NNN, ... 추가
        
        for (int j = 1; j < i; ++j) {
            for (int a : dp[j]) {
                for (int b : dp[i-j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) dp[i].insert(a / b);
                }
            }
        }
        
        if (dp[i].count(number)) return i;
    }
    
    return -1; // 8번 사용해도 찾지 못하면 -1 반환
}