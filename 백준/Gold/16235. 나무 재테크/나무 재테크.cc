#include <iostream>
#include <queue>
#include <algorithm>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M, K;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
struct land
{
    int food;
    vector<int> tree;
    vector<int> death;
};

land make_land(int food, vector<int> tree, vector<int> death)
{
    land temp;
    temp.food = food;
    temp.tree = tree;
    temp.death = death;
    return temp;
}

land myMap[11][11];

int f[11][11];

int main()
{
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;

            f[i][j] = x;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        myMap[x - 1][y - 1].tree.push_back(z);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            myMap[i][j].food = 5;
            if (myMap[i][j].tree.size() > 0)
            {
                sort(myMap[i][j].tree.begin(), myMap[i][j].tree.end());
            }
        }
    }

    for (int t = 1; t <= K; t++)
    {
        // 봄
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (myMap[i][j].tree.size() > 0)
                {
                    vector<int> cur = myMap[i][j].tree;
                    vector<int> temp;
                    sort(cur.begin(), cur.end());

                    for (int k = 0; k < cur.size(); k++)
                    {
                        if (myMap[i][j].food >= cur[k])
                        {
                            myMap[i][j].food -= cur[k];
                            temp.push_back(cur[k] + 1);
                        }
                        else
                        {
                            myMap[i][j].death.push_back(cur[k]);
                        }
                    }

                    sort(temp.begin(), temp.end());
                    myMap[i][j].tree = temp;
                }
            }
        }

        // 여름
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (myMap[i][j].death.size() > 0)
                {
                    vector<int> cur = myMap[i][j].death;
                    vector<int> temp;
                    for (int k = 0; k < cur.size(); k++)
                    {
                        myMap[i][j].food += cur[k] / 2;
                    }
                    myMap[i][j].death = temp;
                }
            }
        }

        // 가을
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (myMap[i][j].tree.size() > 0)
                {
                    vector<int> cur = myMap[i][j].tree;

                    for (int k = 0; k < cur.size(); k++)
                    {
                        if (cur[k] % 5 == 0)
                        {
                            for (int d = 0; d < 8; d++)
                            {
                                int next_x = i + dx[d];
                                int next_y = j + dy[d];

                                if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N)
                                {
                                    myMap[next_x][next_y].tree.push_back(1);
                                }
                            }
                        }
                    }
                }
            }
        }

        // 겨울
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                myMap[i][j].food += f[i][j];
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            answer += myMap[i][j].tree.size();
        }
    }

    cout << answer << endl;

    return 0;
}