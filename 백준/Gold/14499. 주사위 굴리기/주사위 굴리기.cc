#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M, K;

int myMap[25][25];

struct dice
{
    int idx;
    int value;

    dice(int idx, int value) : idx(idx), value(value) {}
    dice() {}
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

dice dices[6];

int main()
{
    FASTIO();
    int x, y;

    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int t;
            cin >> t;

            myMap[i][j] = t;
        }
    }

    dices[0] = dice(3, 0);
    dices[1] = dice(4, 0);
    dices[2] = dice(2, 0);
    dices[3] = dice(5, 0);
    dices[4] = dice(1, 0);
    dices[5] = dice(6, 0);

    for (int k = 0; k < K; k++)
    {
        int d;
        cin >> d;

        int next_x = x + dx[d - 1];
        int next_y = y + dy[d - 1];

        if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M)
        {
            x = next_x;
            y = next_y;
        }
        else
        {
            continue;
        }
        //  동쪽
        if (d == 1)
        {
            dice temp = dices[4];
            dices[4] = dices[1];
            dices[1] = temp;

            temp = dices[5];
            dices[5] = dices[0];
            dices[0] = temp;

            temp = dices[0];
            dices[0] = dices[1];
            dices[1] = temp;
        }
        // 서쪽
        else if (d == 2)
        {
            dice temp = dices[4];
            dices[4] = dices[0];
            dices[0] = temp;

            temp = dices[5];
            dices[5] = dices[1];
            dices[1] = temp;

            temp = dices[0];
            dices[0] = dices[1];
            dices[1] = temp;
        }

        // 북쪽
        else if (d == 3)
        {
            dice temp = dices[4];
            dices[4] = dices[3];
            dices[3] = temp;

            temp = dices[5];
            dices[5] = dices[2];
            dices[2] = temp;

            temp = dices[3];
            dices[3] = dices[2];
            dices[2] = temp;
        }
        // 남쪽
        else if (d == 4)
        {
            dice temp = dices[4];
            dices[4] = dices[2];
            dices[2] = temp;

            temp = dices[5];
            dices[5] = dices[3];
            dices[3] = temp;

            temp = dices[3];
            dices[3] = dices[2];
            dices[2] = temp;
        }

        if (myMap[x][y] == 0)
        {
            myMap[x][y] = dices[5].value;
        }
        else
        {
            dices[5].value = myMap[x][y];
            myMap[x][y] = 0;
        }
        cout << dices[4].value << "\n";
    }
}