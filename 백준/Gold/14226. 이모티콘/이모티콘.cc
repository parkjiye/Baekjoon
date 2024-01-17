#include <iostream>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct emoti {
  int clip;
  int screen;
  int t;

  emoti(int clip, int screen, int t) : clip(clip), screen(screen), t(t) {}
  emoti() {}
};

bool visited[10000][10000];

void bfs(int S) {
  queue<emoti> q;
  q.push(emoti(0, 1, 0));

  // 모든 연산은 1초
  // 클립보드에 이모티콘을 복사하면 클립보드에 있던 내용은 덮어쓰기
  // 클립보드가 비어있는 상태에서는 붙여넣기 x
  // 알부만 붙여넣기 x
  // 클립보드에 있는 이모티콘 중 일부 삭제 x
  // 화면에 이모티콘을 붙여넣기 하면 클립보드에 있는 이모티콘의 개수가 화면에
  // 추가

  while (!q.empty()) {

    emoti cur = q.front();
    q.pop();
    // cout << cur.clip << " " << cur.screen << " " << cur.t << "\n";

    if (cur.screen == S) {
      cout << cur.t << "\n";
      return;
    }
    // 화면에 있는 걸 모두 복사에서 클립보드에 저장
    if (!visited[cur.screen][cur.screen]) {
      q.push(emoti(cur.screen, cur.screen, cur.t + 1));
      visited[cur.screen][cur.screen] = true;
    }

    if (cur.clip != 0 && !visited[cur.clip][cur.screen + cur.clip]) {
      // 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기
      q.push(emoti(cur.clip, cur.screen + cur.clip, cur.t + 1));
      visited[cur.clip][cur.screen + cur.clip] = true;
    }
    if (cur.screen != 0 && !visited[cur.clip][cur.screen - 1]) {
      q.push(emoti(cur.clip, cur.screen - 1, cur.t + 1));
      visited[cur.clip][cur.screen - 1] = true;
    }
  }
}

int main() {

  FASTIO();
  int S;
  cin >> S;

  bfs(S);
}
