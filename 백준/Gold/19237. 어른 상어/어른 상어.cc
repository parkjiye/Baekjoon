#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M, K;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct shark
{
    int idx;
    int dir;

    shark(int idx, int dir) : idx(idx), dir(dir) {}
    shark() {}
};

bool compare(shark a, shark b)
{
    return a.idx < b.idx;
}

struct space
{
    queue<shark> pq;
    int smell;
    int smell_idx;

    space(int smell, int smell_idx, queue<shark> pq) : smell(smell), smell_idx(smell_idx), pq(pq) {}
    space() {}
};

space myMap[30][30];

int main()
{
    FASTIO();
    cin >> N >> M >> K;

    int x;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> x;

            if (x != 0)
            {
                myMap[i][j].pq.push(shark(x, 0));
            }
        }
    }

    vector<int> init_dir;

    for (int i = 0; i < M; i++)
    {
        cin >> x;
        init_dir.push_back(x - 1);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!myMap[i][j].pq.empty())
            {
                int temp = myMap[i][j].pq.front().idx;
                myMap[i][j].pq.pop();
                myMap[i][j].pq.push(shark(temp, init_dir[temp - 1]));
            }
        }
    }

    vector<vector<int>> dir_list;

    for (int i = 0; i < M * 4; i++)
    {
        vector<int> temp;

        for (int k = 0; k < 4; k++)
        {
            int d;
            cin >> d;
            temp.push_back(d - 1);
        }

        dir_list.push_back(temp);
    }
    int t = 0;

    while (M > 1)
    // for (int t = 0; t < 10; t++)
    {
        if (t >= 1000)
        {
            cout << -1 << endl;
            return 0;
        }
        // 냄새뿌리기
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!myMap[i][j].pq.empty())
                {
                    myMap[i][j].smell = K;
                    myMap[i][j].smell_idx = myMap[i][j].pq.front().idx;
                }
            }
        }

        space copy_map[30][30];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                copy_map[i][j] = myMap[i][j];
            }
        }

        // 상어 이동
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!myMap[i][j].pq.empty())
                {
                    shark sh = myMap[i][j].pq.front();
                    vector<int> dirs = dir_list[(sh.idx - 1) * 4 + sh.dir];

                    bool nosmell = false;

                    for (int k = 0; k < 4; k++)
                    {
                        int next_x = i + dx[dirs[k]];
                        int next_y = j + dy[dirs[k]];

                        // 냄새 없는 구간이 있는 경우
                        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && myMap[next_x][next_y].smell == 0)
                        {
                            sh.dir = dirs[k];
                            copy_map[next_x][next_y].pq.push(sh);
                            copy_map[i][j].pq.pop();
                            nosmell = true;

                            break;
                        }
                    }

                    // 냄새 없은 구간이 없는 경우
                    if (!nosmell)
                    {
                        for (int k = 0; k < 4; k++)
                        {
                            int next_x = i + dx[dirs[k]];
                            int next_y = j + dy[dirs[k]];

                            if (myMap[next_x][next_y].smell_idx == sh.idx)
                            {
                                sh.dir = dirs[k];
                                copy_map[next_x][next_y].pq.push(sh);
                                copy_map[i][j].pq.pop();
                                break;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {

                myMap[i][j] = copy_map[i][j];
            }
        }

        // 상어 쫒아내기

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (myMap[i][j].pq.size() > 1)
                {
                    vector<shark> temp;

                    int cnt = myMap[i][j].pq.size() - 1;
                    while (!myMap[i][j].pq.empty())
                    {
                        temp.push_back(myMap[i][j].pq.front());
                        myMap[i][j].pq.pop();
                    }

                    sort(temp.begin(), temp.end(), compare);

                    myMap[i][j].pq.push(temp[0]);

                    M -= cnt;
                }
            }
        }

        // 냄새 없애기
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (myMap[i][j].pq.empty() && myMap[i][j].smell > 0)
                {
                    if (myMap[i][j].smell == 1)
                    {
                        myMap[i][j].smell_idx = 0;
                    }
                    myMap[i][j].smell -= 1;
                }
            }
        }

        t += 1;
    }

    cout << t << endl;

    return 0;
}