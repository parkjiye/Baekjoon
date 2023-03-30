#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct basket
{
    bool cloud;
    bool wascloud;
    int water;
};

basket make_b(int x, bool y, bool z)
{
    basket temp;
    temp.cloud = y;
    temp.water = x;
    temp.wascloud = z;
    return temp;
}

int N, M;
basket myMap[55][55];

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int wx[4] = {-1, -1, 1, 1};
int wy[4] = {-1, 1, 1, -1};

int main()
{
    FASTIO();

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = make_b(x, false, false);
        }
    }

    myMap[N - 1][0].cloud = true;
    myMap[N - 1][1].cloud = true;
    myMap[N - 2][0].cloud = true;
    myMap[N - 2][1].cloud = true;

    for (int move = 0; move < M; move++)
    {
        int d, s;
        cin >> d >> s;

        vector<pair<int, int>> new_cloud;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (myMap[i][j].cloud)
                {
                    int next_x = (N + (i + dx[d - 1] * (s % N))) % N;
                    int next_y = (N + (j + dy[d - 1] * (s % N))) % N;

                    new_cloud.push_back({next_x, next_y});
                    myMap[i][j].cloud = false;
                }

                if (myMap[i][j].wascloud)
                {
                    myMap[i][j].wascloud = false;
                }
            }
        }

        // 구름 이동 및 비 내려서 물의 양 1 증가

        vector<pair<int, int>> new_water;

        for (int i = 0; i < new_cloud.size(); i++)
        {
            int cur_x = new_cloud[i].first;
            int cur_y = new_cloud[i].second;

            myMap[cur_x][cur_y].wascloud = true;
            myMap[cur_x][cur_y].water += 1;

            new_water.push_back({cur_x, cur_y});
        }

        // 물복사
        for (int i = 0; i < new_water.size(); i++)
        {
            int cur_x = new_water[i].first;
            int cur_y = new_water[i].second;

            for (int k = 0; k < 4; k++)
            {
                int next_x = cur_x + wx[k];
                int next_y = cur_y + wy[k];

                if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && myMap[next_x][next_y].water > 0)
                {
                    myMap[cur_x][cur_y].water += 1;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (myMap[i][j].water >= 2 && !myMap[i][j].wascloud)
                {
                    myMap[i][j].cloud = true;
                    myMap[i][j].water -= 2;
                }
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            answer += myMap[i][j].water;
        }
    }

    cout << answer << endl;
}