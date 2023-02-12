/*
정육면체 주사위, 10x10, 1부터 100까지
도착한 칸이 사다리라면 타고 위로 올라간다
뱀이 있는 칸에 도착하면, 뱀을 따라서 내려간다

100번 칸에 도착하기 위해 주사위를 굴려야 하는 횟수의 최솟값
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector<int> myMap[101];
int visited[101];

void bfs()
{
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (myMap[cur].size() != 0)
        {
            if (visited[myMap[cur][0]] == 0 || visited[myMap[cur][0]] > visited[cur])
            {
                visited[myMap[cur][0]] = visited[cur];
                q.push(myMap[cur][0]);
            }
        }
        else
        {
            for (int k = 1; k <= 6; k++)
            {
                int next = cur + k;

                if (next <= 100 && visited[next] == 0 || visited[next] > visited[cur])
                {
                    visited[next] = visited[cur] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        myMap[x].push_back(y);
    }

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        myMap[x].push_back(y);
    }

    bfs();

    cout << visited[100] - 1 << endl;
}