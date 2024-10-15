#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <string.h>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct p
{
    int x;
    int y;

    p() {}
    p(int x, int y) : x(x), y(y) {}
};

vector<p> beer;
bool visited[101];
p start;
p dest;
int n;

void goFestival()
{
    queue<p> q;
    q.push(beer[0]);
    visited[0] = true;

    while (!q.empty())
    {
        p cur = q.front();
        q.pop();

        // cout << cur.x << " " << cur.y << "\n";

        for (int i = 0; i < beer.size(); i++)
        {
            p nxt = beer[i];

            if (!visited[i] && abs(cur.x - nxt.x) + abs(cur.y - nxt.y) <= 1000)
            {
                if (nxt.x == dest.x && nxt.y && dest.y)
                {
                    cout << "happy" << "\n";
                    return;
                }

                q.push(nxt);
                visited[i] = true;
            }
        }
    }

    cout << "sad" << "\n";
}

int main()
{
    FASTIO();
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        beer.clear();
        memset(visited, 0, sizeof(visited));

        int n;
        cin >> n;

        int x, y;
        cin >> x >> y;
        start = p(x + 32768, y + 32768);
        beer.push_back(start);

        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            beer.push_back(p(x + 32768, y + 32768));
        }

        cin >> x >> y;
        dest = p(x + 32768, y + 32768);
        beer.push_back(dest);

        goFestival();
    }
}