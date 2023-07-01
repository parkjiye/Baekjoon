#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct block
{
    int x;
    int y;
    int color;

    block(int x, int y, int color) : x(x), y(y), color(color) {}
    block() {}
};

struct blockgroup
{
    int cnt;
    int rainbow;
    block standard;

    blockgroup(int cnt, int rainbow, block standard) : cnt(cnt), rainbow(rainbow), standard(standard) {}
    blockgroup() {}
};

bool compare(blockgroup a, blockgroup b)
{
    if (a.cnt == b.cnt)
    {
        if (a.rainbow == b.rainbow)
        {
            if (a.standard.x == b.standard.x)
            {
                return a.standard.y > b.standard.y;
            }
            return a.standard.x > b.standard.x;
        }
        return a.rainbow > b.rainbow;
    }
    return a.cnt > b.cnt;
}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;

int myMap[25][25];
bool visited[25][25];
int score;

void gravity()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            if (myMap[j][i] != -1 && myMap[j][i] != 9)
            {
                int cur_x = j;
                int cur_y = i;

                while (1)
                {
                    int next_x = cur_x + 1;

                    if (next_x < N && myMap[next_x][cur_y] == 9)
                    {
                        myMap[next_x][cur_y] = myMap[cur_x][cur_y];
                        myMap[cur_x][cur_y] = 9;
                        cur_x += 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
}

void rotate_90_revs()
{
    int temp[25][25];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp[N - j - 1][i] = myMap[i][j];
        }
    }

    memcpy(myMap, temp, sizeof(temp));
}

int main()
{
    FASTIO();
    cin >> N >> M;
    score = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = x;
        }
    }

    // for (int t = 0; t < 5; t++)
    while (1)
    {
        vector<block> blocks;

        // 일반 블록 조사
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (myMap[i][j] > 0 && myMap[i][j] != 9)
                {
                    blocks.push_back(block(i, j, myMap[i][j]));
                }
            }
        }

        vector<blockgroup> bg_list;

        // 블록 그룹 만들기
        for (int i = 0; i < blocks.size(); i++)
        {
            memset(visited, 0, sizeof(visited));
            queue<block> q;
            blockgroup bg = blockgroup(1, 0, blocks[i]);

            q.push(blocks[i]);
            visited[blocks[i].x][blocks[i].y] = true;

            int color = blocks[i].color;

            while (!q.empty())
            {
                block cur = q.front();
                q.pop();

                if (cur.color != 0)
                {
                    if (cur.x < bg.standard.x)
                    {
                        bg.standard = cur;
                    }
                    else if (cur.x == bg.standard.x && cur.y < bg.standard.y)
                    {
                        bg.standard = cur;
                    }
                }

                for (int k = 0; k < 4; k++)
                {
                    int next_x = cur.x + dx[k];
                    int next_y = cur.y + dy[k];

                    if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && !visited[next_x][next_y] && myMap[next_x][next_y] != -1)
                    {
                        if (myMap[next_x][next_y] == 0)
                        {
                            bg.rainbow += 1;
                            bg.cnt += 1;
                            visited[next_x][next_y] = true;
                            q.push(block(next_x, next_y, myMap[next_x][next_y]));
                        }
                        else if (myMap[next_x][next_y] == color)
                        {
                            bg.cnt += 1;
                            visited[next_x][next_y] = true;
                            q.push(block(next_x, next_y, myMap[next_x][next_y]));
                        }
                    }
                }
            }

            if (bg.cnt >= 2)
            {
                bg_list.push_back(bg);
            }
        }

        if (bg_list.size() <= 0)
        {
            break;
        }

        sort(bg_list.begin(), bg_list.end(), compare);

        blockgroup bg = bg_list[0];
        score += (bg.cnt * bg.cnt);

        queue<block> q;
        q.push(bg.standard);
        memset(visited, 0, sizeof(visited));
        myMap[bg.standard.x][bg.standard.y] = 9;

        while (!q.empty())
        {
            block cur = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int next_x = cur.x + dx[k];
                int next_y = cur.y + dy[k];

                if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && !visited[next_x][next_y] && myMap[next_x][next_y] != -1)
                {
                    if (myMap[next_x][next_y] == 0 || myMap[next_x][next_y] == bg.standard.color)
                    {
                        visited[next_x][next_y] = true;
                        myMap[next_x][next_y] = 9;
                        q.push(block(next_x, next_y, myMap[next_x][next_y]));
                    }
                }
            }
        }

        // 중력 작용
        gravity();
        rotate_90_revs();
        gravity();
    }

    cout << score << endl;
}