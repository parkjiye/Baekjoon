#include <iostream>
#include <queue>
#include <math.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
int stars[105];
pair<double, double> dist[105];

struct p
{
    int x;
    int y;
    double s;

    bool operator<(const p temp) const
    {
        if (s > temp.s)
        {
            return true;
        }
        return false;
    }

    p(int x, int y, double s) : x(x), y(y), s(s) {}
    p() {}
};

priority_queue<p> pq;

int findParents(int idx)
{
    if (idx == stars[idx])
    {
        return idx;
    }
    else
    {
        return stars[idx] = findParents(stars[idx]);
    }
}

int main()
{
    FASTIO();
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        stars[i] = i;

        double x, y;
        cin >> x >> y;

        dist[i] = {x, y};
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (i != j)
            {
                double row = abs(dist[i].first - dist[j].first);
                double col = abs(dist[i].second - dist[j].second);

                pq.push(p(i, j, sqrt(row * row + col * col)));
            }
        }
    }

    double galaxy = 0;

    while (!pq.empty())
    {
        p cur = pq.top();
        pq.pop();

        int a = findParents(cur.x);
        int b = findParents(cur.y);

        if (a < b)
        {
            stars[b] = a;
            galaxy += cur.s;
        }
        else if (a == b)
        {
            continue;
        }
        else
        {
            stars[a] = b;
            galaxy += cur.s;
        }
    }

    cout << fixed;
    cout.precision(2);

    cout << galaxy << endl;
}