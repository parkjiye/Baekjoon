#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int N, K;
vector<vector<int>> arr;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

void push_fish()
{
    int min = *min_element(arr[N - 1].begin(), arr[N - 1].end());

    for (int i = 0; i < N; i++)
    {
        if (arr[N - 1][i] == min)
        {
            arr[N - 1][i] += 1;
        }
    }
}

vector<vector<int>> rotate_90(vector<vector<int>> graph)
{
    vector<vector<int>> newgraph(graph[0].size(), vector<int>(graph.size(), 0));

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[0].size(); j++)
        {
            newgraph[j][graph.size() - i - 1] = graph[i][j];
        }
    }

    return newgraph;
}

vector<vector<int>> rotate_180(vector<vector<int>> graph)
{
    vector<vector<int>> newgraph(graph[0].size(), vector<int>(graph.size(), 0));

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[0].size(); j++)
        {
            newgraph[j][graph.size() - i - 1] = graph[i][j];
        }
    }

    graph.assign(newgraph[0].size(), vector<int>(graph.size(), 0));

    for (int i = 0; i < newgraph.size(); i++)
    {
        for (int j = 0; j < newgraph[0].size(); j++)
        {
            graph[j][newgraph.size() - i - 1] = newgraph[i][j];
        }
    }

    return graph;
}

void rotate_ver1()
{
    int cur_height = 1;
    int cur_left = N;
    // 가장 왼쪽 어항을 오른쪽에 있는 어항의 위
    arr[N - 2][1] = arr[N - 1][0];
    arr[N - 1][0] = 0;

    cur_height += 1;
    cur_left -= 2;

    // for (int k = 0; k < 1; k++)
    while (cur_height <= cur_left)
    {
        vector<int> height;
        int width = 0;

        for (int i = 0; i < N; i++)
        {
            int h = 0;

            for (int j = 0; j < N; j++)
            {
                if (arr[j][i] != 0)
                {
                    h += 1;
                }
            }

            if (h > 1)
            {
                width += 1;
            }

            height.push_back(h);
        }

        vector<vector<int>> temp;
        temp.assign(cur_height, vector<int>(width, 0));

        int w = 0;

        for (int i = 0; i < N; i++)
        {
            if (height[i] > 1)
            {
                int h = 0;
                for (int j = N - cur_height; j < N; j++)
                {
                    temp[h][w] = arr[j][i];
                    arr[j][i] = 0;
                    h += 1;
                }
                w += 1;
            }
        }

        temp = rotate_90(temp);

        for (int i = 0; i < temp.size(); i++)
        {
            for (int j = 0; j < temp[0].size(); j++)
            {
                arr[N - temp.size() - 1 + i][N - cur_left + j] = temp[i][j];
            }
        }

        cur_left -= temp[0].size();

        if (temp.size() + 1 > cur_height)
        {
            cur_height = temp.size() + 1;
        }
    }
}

void control_fish()
{
    vector<vector<int>> temp = arr;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] != 0)
            {
                for (int k = 0; k < 2; k++)
                {
                    int next_x = i + dx[k];
                    int next_y = j + dy[k];

                    if (next_x < N && next_y < N && arr[next_x][next_y] != 0)
                    {
                        int diff = abs(arr[i][j] - arr[next_x][next_y]) / 5;
                        if (diff > 0)
                        {
                            if (arr[i][j] > arr[next_x][next_y])
                            {
                                temp[next_x][next_y] += diff;
                                temp[i][j] -= diff;
                            }
                            else
                            {
                                temp[next_x][next_y] -= diff;
                                temp[i][j] += diff;
                            }
                        }
                    }
                }
            }
        }
    }

    arr = temp;
}

void make_straight()
{
    vector<vector<int>> temp;
    temp.assign(N, vector<int>(N, 0));

    int idx = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            if (arr[j][i] != 0)
            {
                temp[N - 1][idx] = arr[j][i];
                idx += 1;
            }
        }
    }

    arr = temp;
}

void rotate_ver2()
{
    // N/2
    vector<vector<int>> first_half;
    first_half.assign(1, vector<int>(N / 2, 0));

    for (int i = 0; i < N / 2; i++)
    {
        first_half[0][i] = arr[N - 1][i];
        arr[N - 1][i] = 0;
    }

    first_half = rotate_180(first_half);

    for (int i = N / 2; i < N; i++)
    {
        arr[N - 2][i] = first_half[0][i - N / 2];
    }

    // N/4
    vector<vector<int>> second_half;
    second_half.assign(2, vector<int>(N / 4, 0));

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N / 4; j++)
        {
            second_half[i][j] = arr[N - 2 + i][N / 2 + j];
            arr[N - 2 + i][N / 2 + j] = 0;
        }
    }

    second_half = rotate_180(second_half);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N / 4; j++)
        {
            arr[N - 4 + i][N / 2 + N / 4 + j] = second_half[i][j];
        }
    }
}

int main()
{
    FASTIO();
    cin >> N >> K;

    arr.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        arr[N - 1][i] = x;
    }

    int max_fish = *max_element(arr[N - 1].begin(), arr[N - 1].end());
    int min_fish = *min_element(arr[N - 1].begin(), arr[N - 1].end());

    if (max_fish - min_fish <= K)
    {
        cout << 0 << endl;
        return 0;
    }

    int turn = 1;

    // for (int k = 0; k < 2; k++)
    while (1)
    {
        push_fish();
        rotate_ver1();
        control_fish();
        make_straight();
        rotate_ver2();
        control_fish();
        make_straight();

        int max_fish = *max_element(arr[N - 1].begin(), arr[N - 1].end());
        int min_fish = *min_element(arr[N - 1].begin(), arr[N - 1].end());

        if (max_fish - min_fish <= K)
        {
            cout << turn << endl;
            return 0;
        }

        turn += 1;
    }
}