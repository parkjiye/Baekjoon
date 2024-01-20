#include <iostream>
#include <string.h>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int answer = 0;
bool blue[4][6];
bool green[6][4];

void print_blue() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      cout << blue[i][j] << " ";
    }
    cout << "\n";
  }
}

void print_green() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      cout << green[i][j] << " ";
    }
    cout << "\n";
  }
}

void set_green(int t, int x, int y) {
  int cur_x = 0;
  int cur_y;
  if (t == 1 || t == 3) {
    cur_y = y;
    while (cur_x < 5 && !green[cur_x][cur_y]) {
      if (!green[cur_x + 1][cur_y]) {
        cur_x += 1;
      } else {
        break;
      }
    }
    if (t == 3) {
      green[cur_x - 1][cur_y] = true;
    }
    green[cur_x][cur_y] = true;
  } else {
    cur_y = y;
    while (cur_x < 5 && !green[cur_x][cur_y] && !green[cur_x][cur_y + 1]) {
      if (!green[cur_x + 1][cur_y] && !green[cur_x + 1][cur_y + 1]) {
        cur_x += 1;
      } else {
        break;
      }
    }
    green[cur_x][cur_y] = true;
    green[cur_x][cur_y + 1] = true;
  }
}

void set_blue(int t, int x, int y) {
  int cur_x, cur_y = 0;
  if (t == 1 || t == 2) {
    cur_x = x;
    while (cur_y < 5 && !blue[cur_x][cur_y]) {
      if (!blue[cur_x][cur_y + 1]) {
        cur_y += 1;
      } else {
        break;
      }
    }
    if (t == 2) {
      blue[cur_x][cur_y - 1] = true;
    }
    blue[cur_x][cur_y] = true;
  } else {
    cur_x = x;
    while (cur_y < 5 && !blue[cur_x][cur_y] && !blue[cur_x + 1][cur_y]) {
      if (!blue[cur_x][cur_y + 1] && !blue[cur_x + 1][cur_y + 1]) {
        cur_y += 1;
      } else {
        break;
      }
    }
    blue[cur_x][cur_y] = true;
    blue[cur_x + 1][cur_y] = true;
  }
}

void check_blue() {
  for (int i = 0; i < 6; i++) {
    int cnt = 0;
    for (int j = 0; j < 4; j++) {
      if (!blue[j][i]) {
        break;
      } else {
        cnt += 1;
      }
    }
    if (cnt == 4) {
      answer += 1;
      for (int j = 0; j < 4; j++) {
        blue[j][i] = false;
      }
      for (int k = i; k > 0; k--) {
        for (int j = 0; j < 4; j++) {
          blue[j][k] = blue[j][k - 1];
        }
      }
    }
  }
}

void check_green() {
  for (int i = 0; i < 6; i++) {
    int cnt = 0;
    for (int j = 0; j < 4; j++) {
      if (!green[i][j]) {
        break;
      } else {
        cnt += 1;
      }
    }

    if (cnt == 4) {
      answer += 1;
      for (int j = 0; j < 4; j++) {
        green[i][j] = false;
      }
      for (int k = i; k > 0; k--) {
        for (int j = 0; j < 4; j++) {
          green[k][j] = green[k - 1][j];
        }
      }
    }
  }
}

void light_blue() {
  int cnt = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      if (blue[j][i]) {
        cnt += 1;
        break;
      }
    }
  }

  if (cnt == 1) {
    for (int j = 0; j < 4; j++) {
      blue[j][5] = false;
    }
    for (int k = 5; k > 0; k--) {
      for (int j = 0; j < 4; j++) {
        blue[j][k] = blue[j][k - 1];
      }
    }
  } else if (cnt == 2) {
    for (int j = 0; j < 4; j++) {
      blue[j][5] = false;
      blue[j][4] = false;
    }
    for (int k = 5; k > 1; k--) {
      for (int j = 0; j < 4; j++) {
        blue[j][k] = blue[j][k - 2];
      }
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      blue[j][i] = false;
    }
  }
}

void light_green() {
  int cnt = 0;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      if (green[i][j]) {
        cnt += 1;
        break;
      }
    }
  }

  if (cnt == 1) {
    for (int j = 0; j < 4; j++) {
      green[5][j] = false;
    }
    for (int k = 5; k > 0; k--) {
      for (int j = 0; j < 4; j++) {
        green[k][j] = green[k - 1][j];
      }
    }
  } else if (cnt == 2) {
    for (int j = 0; j < 4; j++) {
      green[5][j] = false;
      green[4][j] = false;
    }
    for (int k = 5; k > 1; k--) {
      for (int j = 0; j < 4; j++) {
        green[k][j] = green[k - 2][j];
      }
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      green[i][j] = false;
    }
  }
}
int main() {
  FASTIO();
  cin >> N;

  memset(blue, false, sizeof(blue));
  memset(green, false, sizeof(green));

  for (int i = 0; i < N; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    // 파란색 쪽으로 블록을 민다

    set_blue(t, x, y);
    // print_blue();

    // 초록색 쪽으로 블록을 민다
    set_green(t, x, y);
    // print_green();
    //   각각 행이나 열이 가득찼는지 확인하고 없애고 민다

    check_blue();
    // print_blue();

    check_green();
    // print_green();

    // 연한칸에 블록이 있는지 확인하고 민다

    light_blue();
    // print_blue();

    light_green();
    // print_green();
  }

  cout << answer << "\n";

  int b = 0;
  int g = 0;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      if (blue[i][j]) {
        b += 1;
      }
      if (green[j][i]) {
        g += 1;
      }
    }
  }

  cout << b + g << "\n";
}
