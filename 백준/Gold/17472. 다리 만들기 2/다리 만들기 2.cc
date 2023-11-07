#include <iostream>
#include <queue>
#include <string.h>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int myMap[105][105];
bool visited[105][105];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cnt = 1;
int parents[8];

struct p
{
    int x;
    int y;

    p() {}
    p(int x, int y) : x(x), y(y) {}
};

struct island
{
    int a;
    int b;
    int dist;

    island() {}
    island(int a, int b, int dist) : a(a), b(b), dist(dist) {}

    bool operator<(const island temp) const
    {
        return dist > temp.dist;
    }
};

priority_queue<island> pq;

void bfs(p start, int cnt)
{
    queue<p> q;

    q.push(start);
    visited[start.x][start.y] = true;
    myMap[start.x][start.y] = cnt;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && !visited[next_x][next_y] && myMap[next_x][next_y] == 1)
            {
                q.push(p(next_x, next_y));
                myMap[next_x][next_y] = cnt;
                visited[next_x][next_y] = true;
            }
        }
    }
}

void find_island()
{
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (myMap[i][j] == 1 && !visited[i][j])
            {
                bfs(p(i, j), cnt);
                cnt += 1;
            }
        }
    }
}
void calculate_distance(p start, int d, int i)
{
    int dist = 1;

    while (1)
    {
        int next_x = start.x + dx[d];
        int next_y = start.y + dy[d];

        if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M)
        {
            return;
        }
        else if (myMap[next_x][next_y] == 0)
        {
            dist += 1;
            start.x = next_x;
            start.y = next_y;
        }
        else if (myMap[next_x][next_y] != 0 && myMap[next_x][next_y] != i)
        {
            pq.push(island(i, myMap[next_x][next_y], dist));
            return;
        }
        else
        {
            return;
        }
    }
}

void find_distance()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (myMap[i][j] != 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    int next_x = i + dx[k];
                    int next_y = j + dy[k];

                    if (myMap[next_x][next_y] == 0 && next_x >= 0 && next_y >= 0 && next_x < N && next_y < M)
                    {
                        calculate_distance(p(next_x, next_y), k, myMap[i][j]);
                    }
                }
            }
        }
    }
}

int findParents(int idx)
{
    if (idx == parents[idx])
    {
        return idx;
    }
    else
    {
        return parents[idx] = findParents(parents[idx]);
    }
}

int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = x;
        }
    }

    // 섬 찾기
    find_island();

    // 섬끼리 거리 측정하기
    find_distance();

    // MST
    for (int i = 1; i < cnt; i++)
    {
        parents[i] = i;
    }

    int answer = 0;

    while (!pq.empty())
    {
        island cur = pq.top();
        pq.pop();

        if (cur.dist < 2)
        {
            continue;
        }

        int a = findParents(cur.a);
        int b = findParents(cur.b);

        if (a == b)
        {
            continue;
        }
        else if (a < b)
        {
            parents[b] = a;
            answer += cur.dist;
        }
        else
        {
            parents[a] = b;
            answer += cur.dist;
        }
    }
    // cout << answer << " " << cnt << "\n";

    for (int i = 1; i < cnt - 1; i++)
    {
        // cout << findParents(i) << " " << findParents(i + 1) << endl;
        if (findParents(i) != findParents(i + 1))
        {
            answer = 0;
            break;
        }
    }

    cout << (answer == 0 ? -1 : answer) << "\n";
}