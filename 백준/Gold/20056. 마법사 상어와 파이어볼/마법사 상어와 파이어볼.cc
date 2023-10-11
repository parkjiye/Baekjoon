#include <iostream>
#include <vector>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M, K;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct fireball
{
    int m;
    int d;
    int s;

    fireball(int m, int d, int s) : m(m), d(d), s(s) {}
    fireball() {}
};

vector<fireball> myMap[55][55];

int main()
{
    FASTIO();
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;

        myMap[r - 1][c - 1].push_back(fireball(m, d, s));
    }

    for (int k = 0; k < K; k++)
    {
        vector<fireball> temp[55][55];
        vector<fireball> temp_2[55][55];

        // 자신의 방향으로 이동
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (myMap[i][j].size())
                {
                    for (int t = 0; t < myMap[i][j].size(); t++)
                    {
                        fireball cur = myMap[i][j][t];

                        int next_x = (i + (dx[cur.d] * cur.s) % N + N) % N;
                        int next_y = (j + (dy[cur.d] * cur.s) % N + N) % N;

                        temp[next_x][next_y].push_back(cur);
                    }
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                myMap[i][j] = temp[i][j];
            }
        }

        // 2개 이상의 파이어볼이 있으면 나누기

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (myMap[i][j].size() >= 2)
                {
                    int total_m = 0;
                    int total_s = 0;

                    vector<bool> v;
                    int new_dir = 0;

                    for (int t = 0; t < myMap[i][j].size(); t++)
                    {
                        total_m += myMap[i][j][t].m;
                        total_s += myMap[i][j][t].s;

                        if (myMap[i][j][t].d % 2 == 1)
                        {
                            v.push_back(true);
                        }
                        else
                        {
                            v.push_back(false);
                        }
                    }

                    for (int t = 0; t < v.size() - 1; t++)
                    {
                        if (v[t] != v[t + 1])
                        {
                            new_dir = 1;
                            break;
                        }
                    }

                    total_m /= 5;
                    total_s /= myMap[i][j].size();

                    if (total_m != 0)
                    {
                        for (int t = 0; t < 4; t++)
                        {
                            temp_2[i][j].push_back(fireball(total_m, new_dir, total_s));
                            new_dir += 2;
                        }
                    }
                }
                else if (myMap[i][j].size() == 1)
                {
                    temp_2[i][j].push_back(myMap[i][j][0]);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                myMap[i][j] = temp_2[i][j];
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            if (myMap[i][j].size() > 0)
            {
                for (int t = 0; t < myMap[i][j].size(); t++)
                {
                    answer += myMap[i][j][t].m;
                }
            }
        }
    }

    cout << answer << "\n";
    return 0;
}