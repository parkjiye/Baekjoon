#include <iostream>
#include <math.h>

using namespace std;

int cnt;
int answer;

int N, r, c;

void dive(int N, int x, int y)
{
    if (x == r && y == c)
    {
        cout << answer << endl;
        return;
    }

    if (r >= x && r < x + N && c >= y && c < y + N)
    {
        dive(N / 2, x, y);
        dive(N / 2, x, y + N / 2);
        dive(N / 2, x + N / 2, y);
        dive(N / 2, x + N / 2, y + N / 2);
    }
    else
    {
        answer += N * N;
    }
}

int main()
{
    cin >> N >> r >> c;

    answer = 0;
    cnt = 0;

    dive(pow(2, N), 0, 0);
}