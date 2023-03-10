#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N, M;
int myMap[50][50];
bool visited[50][50];
int dist[50][50];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct p
{
    int x;
    int y;
};

p make_p(int x, int y)
{
    p temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

vector<p> chicken;
vector<p> house;

int arr[15];
int answer;

void select_chicken(int idx)
{
    if (idx == M)
    {
        vector<p> selected;
        for (int i = 0; i < M; i++)
        {
            selected.push_back(chicken[arr[i]]);
        }

        int sum = 0;

        for (int i = 0; i < house.size(); i++)
        {
            int min = INT16_MAX;

            for (int j = 0; j < selected.size(); j++)
            {
                int dis = abs(house[i].x - selected[j].x) + abs(house[i].y - selected[j].y);
                if (dis < min)
                    min = dis;
            }

            sum += min;
        }

        if (sum < answer)
            answer = sum;
    }
    else
    {
        for (int i = 0; i < chicken.size(); i++)
        {
            if (idx == 0 || arr[idx - 1] < i)
            {
                arr[idx] = i;
                select_chicken(idx + 1);
            }
        }
    }
}

// 치킨 거리 == 집과 가장 가까운 치킨집 사이의 거리
// 도시의 치킨 거리 == 모든 집의 치킨 거리의 합
// 0 빈칸 1 집 2 치킨집
// 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업 -> 도시의 치킨 거리가 가장 작은 경우
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;

            if (x == 2)
                chicken.push_back(make_p(i, j));

            if (x == 1)
                house.push_back(make_p(i, j));
        }
    }

    answer = INT16_MAX;
    select_chicken(0);

    cout << answer << endl;
}