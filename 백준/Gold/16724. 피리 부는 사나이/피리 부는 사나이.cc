#include <iostream>
#include <set>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int myMap[1005][1005];
int safezone[1000009];

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y) {}
    p() {}
};

int findParents(int idx)
{
    if (idx == safezone[idx])
    {
        return idx;
    }
    else
    {
        return safezone[idx] = findParents(safezone[idx]);
    }
}

int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++)
        {
            char c = s[j];

            if (c == 'U')
            {
                myMap[i][j] = 0;
            }
            else if (c == 'D')
            {
                myMap[i][j] = 1;
            }
            else if (c == 'L')
            {
                myMap[i][j] = 2;
            }
            else
            {
                myMap[i][j] = 3;
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= N * M; i++)
    {
        safezone[i] = i;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int next_x = i + dx[myMap[i][j]];
            int next_y = j + dy[myMap[i][j]];

            int a = findParents(i * M + (j + 1));
            int b = findParents(next_x * M + (next_y + 1));

            if (a < b)
            {
                safezone[b] = a;
            }
            else
            {
                safezone[a] = b;
            }
        }
    }

    set<int> s;

    for (int i = 1; i <= N * M; i++)
    {
        s.insert(findParents(safezone[i]));
    }

    cout << s.size() << endl;
}