#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int myMap[10][10];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = 100;

struct cctv
{
    int x;
    int y;
    int t;

    cctv(int x, int y, int t) : x(x), y(y), t(t) {}
    cctv() {}
};

struct p
{
    int x;
    int y;
    int dir;

    p(int x, int y, int dir) : x(x), y(y), dir(dir) {}
    p() {}
};

vector<cctv> v;

void check(queue<p> q)
{
    while (!q.empty())
    {
        p now = q.front();
        q.pop();

        int next_x = now.x + dx[now.dir];
        int next_y = now.y + dy[now.dir];

        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
        {
            if (myMap[next_x][next_y] != 6)
            {
                myMap[next_x][next_y] = 7;
                q.push(p(next_x, next_y, now.dir));
            }
        }
    }
}

void camera1(cctv cur, int d)
{
    queue<p> q;

    int next_x = cur.x + dx[d];
    int next_y = cur.y + dy[d];

    if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && myMap[next_x][next_y] != 6)
    {
        myMap[next_x][next_y] = 7;
        q.push(p(next_x, next_y, d));
        check(q);
    }
}

void camera2(cctv cur, int d)
{
    queue<p> q;

    if (d == 1)
    {
        for (int i = 2; i < 4; i++)
        {
            int next_x = cur.x + dx[i];
            int next_y = cur.y + dy[i];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && myMap[next_x][next_y] != 6)
            {
                myMap[next_x][next_y] = 7;
                q.push(p(next_x, next_y, i));
            }
        }
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            int next_x = cur.x + dx[i];
            int next_y = cur.y + dy[i];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && myMap[next_x][next_y] != 6)
            {
                myMap[next_x][next_y] = 7;
                q.push(p(next_x, next_y, i));
            }
        }
    }

    check(q);
}

void check_2(cctv cur, int x, int y)
{
    queue<p> q;

    int next_x = cur.x + dx[x];
    int next_y = cur.y + dy[x];

    if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && myMap[next_x][next_y] != 6)
    {
        myMap[next_x][next_y] = 7;
        q.push(p(next_x, next_y, x));
    }

    next_x = cur.x + dx[y];
    next_y = cur.y + dy[y];

    if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && myMap[next_x][next_y] != 6)
    {
        myMap[next_x][next_y] = 7;
        q.push(p(next_x, next_y, y));
    }

    check(q);
}

void camera3(cctv cur, int d)
{
    if (d == 1) // 상우
    {
        check_2(cur, 1, 3);
    }
    else if (d == 2) // 우하
    {
        check_2(cur, 3, 0);
    }
    else if (d == 3) // 하좌
    {
        check_2(cur, 0, 2);
    }
    else
    {
        check_2(cur, 2, 1);
    }
}

void camera4(cctv cur, int d)
{
    queue<p> q;

    for (int i = 0; i < 4; i++)
    {
        if (i == d)
        {
            continue;
        }

        int next_x = cur.x + dx[i];
        int next_y = cur.y + dy[i];

        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && myMap[next_x][next_y] != 6)
        {
            myMap[next_x][next_y] = 7;
            q.push(p(next_x, next_y, i));
        }
    }

    check(q);
}

void camera5(cctv cur)
{
    queue<p> q;

    for (int i = 0; i < 4; i++)
    {
        int next_x = cur.x + dx[i];
        int next_y = cur.y + dy[i];

        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && myMap[next_x][next_y] != 6)
        {
            myMap[next_x][next_y] = 7;
            q.push(p(next_x, next_y, i));
        }
    }

    check(q);
}

int nocameraarea()
{
    int area = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (myMap[i][j] == 0)
            {
                area += 1;
            }
        }
    }

    if (area < ans)
    {
        ans = area;
        return area;
    }

    return ans;
}

void print_map()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << myMap[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void inspect(int idx)
{
    int temp[10][10];
    memcpy(temp, myMap, sizeof(myMap));

    if (v[idx].t == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            camera1(v[idx], i);

            if (idx == v.size() - 1)
            {
                nocameraarea();
            }
            else
            {
                inspect(idx + 1);
            }

            memcpy(myMap, temp, sizeof(temp));
        }
    }
    else if (v[idx].t == 2)
    {
        // 좌우
        camera2(v[idx], 1);

        if (idx == v.size() - 1)
        {
            nocameraarea();
        }
        else
        {
            inspect(idx + 1);
        }

        memcpy(myMap, temp, sizeof(temp));

        // 상하
        camera2(v[idx], 2);

        if (idx == v.size() - 1)
        {
            nocameraarea();
        }
        else
        {
            inspect(idx + 1);
        }
        memcpy(myMap, temp, sizeof(temp));
    }
    else if (v[idx].t == 3)
    {
        for (int i = 1; i <= 4; i++)
        {
            camera3(v[idx], i);

            if (idx == v.size() - 1)
            {
                nocameraarea();
            }
            else
            {
                inspect(idx + 1);
            }

            memcpy(myMap, temp, sizeof(temp));
        }
    }
    else if (v[idx].t == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            camera4(v[idx], i);

            if (idx == v.size() - 1)
            {
                nocameraarea();
            }
            else
            {
                inspect(idx + 1);
            }

            memcpy(myMap, temp, sizeof(temp));
        }
    }
    else
    {
        camera5(v[idx]);

        if (idx == v.size() - 1)
        {
            nocameraarea();
            memcpy(myMap, temp, sizeof(temp));
        }
        else
        {
            inspect(idx + 1);
            memcpy(myMap, temp, sizeof(temp));
        }
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

            if (x != 0 && x != 6)
            {
                v.push_back(cctv(i, j, x));
            }
        }
    }

    if (v.size() == 0)
    {
        nocameraarea();
    }
    else
    {
        inspect(0);
    }

    cout << ans << endl;
}