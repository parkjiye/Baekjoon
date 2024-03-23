#include <iostream>
#include <queue>
#include <string.h>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int T;
int x, y;
int key = 0;
struct p
{
    int x;
    int y;

    p() {}
    p(int x, int y) : x(x), y(y) {}
};

char myMap[105][105];
bool visited[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(p start)
{
    memset(visited, 0, sizeof(visited));
    queue<p> q;
    q.push(start);
    visited[start.x][start.y] = true;
    int doc = 0;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if (next_x >= 0 && next_x < x && next_y >= 0 && next_y < y && !visited[next_x][next_y])
            {
                if (myMap[next_x][next_y] == '.')
                {
                    q.push(p(next_x, next_y));
                }
                else if (myMap[next_x][next_y] >= 'a' && myMap[next_x][next_y] <= 'z')
                {
                    int c = myMap[next_x][next_y] - 'a';
                    key = key | 1 << c;
                    // cout << "found key " << myMap[next_x][next_y] << "\n";
                    myMap[next_x][next_y] = '.';
                    q.push(p(next_x, next_y));
                }
                else if (myMap[next_x][next_y] >= 'A' && myMap[next_x][next_y] <= 'Z')
                {
                    int c = myMap[next_x][next_y] - 'A';
                    if (key & 1 << c)
                    {
                        myMap[next_x][next_y] = '.';
                        q.push(p(next_x, next_y));
                    }
                }
                else if (myMap[next_x][next_y] == '$')
                {
                    doc += 1;
                    myMap[next_x][next_y] = '.';
                    q.push(p(next_x, next_y));
                }

                visited[next_x][next_y] = true;
            }
        }
    }

    return doc;
}

int main()
{
    FASTIO();
    cin >> T;

    for (int t = 0; t < T; t++)
    {

        cin >> x >> y;

        for (int i = 0; i < x; i++)
        {
            string str;
            cin >> str;

            for (int j = 0; j < y; j++)
            {
                myMap[i][j] = str[j];
            }
        }

        string keys;
        key = 0;
        cin >> keys;

        if (keys.compare("0") != 0)
        {
            for (int i = 0; i < keys.length(); i++)
            {
                int c = keys[i] - 'a';
                key = key | 1 << c;
            }
        }

        int answer = 0;
        // cout << key << "\n";

        vector<p> v;

        while (1)
        {
            int cur_k = key;

            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    if (i == 0 || j == 0 || i == x - 1 || j == y - 1)
                    {
                        if (myMap[i][j] == '.')
                        {
                            v.push_back(p(i, j));
                        }
                        else if (myMap[i][j] >= 'A' && myMap[i][j] <= 'Z')
                        {
                            int c = myMap[i][j] - 'A';
                            if (key & 1 << c)
                            {
                                v.push_back(p(i, j));
                            }
                        }
                        else if (myMap[i][j] >= 'a' && myMap[i][j] <= 'z')
                        {
                            int c = myMap[i][j] - 'a';
                            key = key | 1 << c;
                            v.push_back(p(i, j));
                            myMap[i][j] = '.';
                        }
                        else if (myMap[i][j] == '$')
                        {
                            myMap[i][j] = '.';
                            answer += 1;
                            v.push_back(p(i, j));
                        }
                    }
                }
            }

            for (int i = 0; i < v.size(); i++)
            {
                answer += bfs(v[i]);
            }

            if (cur_k == key)
            {
                break;
            }
        }

        cout << answer << "\n";
    }
}