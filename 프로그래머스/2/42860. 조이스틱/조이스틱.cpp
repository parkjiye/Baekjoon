#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    int minUpDown = n - 1; // 최대로 움직일 수 있는 상하 이동 횟수는 커서 이동 횟수와 같음

    for (int i = 0; i < n; ++i) {
        // 상하 이동 횟수 계산
        int upDown = min(name[i] - 'A', 'Z' - name[i] + 1);
        answer += upDown;

        // 커서를 왼쪽으로 이동했을 때와 오른쪽으로 이동했을 때의 최소 횟수 구하기
        int next = i + 1;
        while (next < n && name[next] == 'A') next++; // 다음 문자가 'A'인 경우 다음 문자로 계속 이동
        minUpDown = min(minUpDown, i + n - next + min(i, n - next));
    }

    // 상하 이동 횟수와 좌우 이동 횟수의 합이 정답
    answer += minUpDown;
    
    return answer;
}
