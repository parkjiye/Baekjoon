#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int galaxy[100005];

struct p
{
    int idx;
    int x;
    int y;
    int z;

    p(int idx, int x, int y, int z) : idx(idx), x(x), y(y), z(z) {}
    p() {}
};

bool comparator_1(p a, p b)
{
    return a.x < b.x;
}

bool comparator_2(p a, p b)
{
    return a.y < b.y;
}

bool comparator_3(p a, p b)
{
    return a.z < b.z;
}

struct planet
{
    int from;
    int to;
    int dist;

    planet(int from, int to, int dist) : from(from), to(to), dist(dist) {}
    planet() {}

    bool operator<(const planet temp) const
    {
        return dist > temp.dist;
    }
};

priority_queue<planet> pq;

int findParents(int idx)
{
    if (idx == galaxy[idx])
    {
        return idx;
    }
    else
    {
        return galaxy[idx] = findParents(galaxy[idx]);
    }
}

int main()
{
    FASTIO();
    cin >> N;

    vector<p> v;

    for (int i = 0; i < N; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        v.push_back(p(i + 1, x, y, z));
    }

    // x좌표끼리 비교
    sort(v.begin(), v.end(), comparator_1);

    for (int i = 0; i < N - 1; i++)
    {
        int a = abs(v[i].x - v[i + 1].x);

        pq.push(planet(v[i].idx, v[i + 1].idx, a));
    }

    // y좌표끼리 비교
    sort(v.begin(), v.end(), comparator_2);

    for (int i = 0; i < N - 1; i++)
    {
        int b = abs(v[i].y - v[i + 1].y);

        pq.push(planet(v[i].idx, v[i + 1].idx, b));
    }

    // x좌표끼리 비교
    sort(v.begin(), v.end(), comparator_3);

    for (int i = 0; i < N - 1; i++)
    {
        int c = abs(v[i].z - v[i + 1].z);

        pq.push(planet(v[i].idx, v[i + 1].idx, c));
    }

    for (int i = 1; i <= N; i++)
    {
        galaxy[i] = i;
    }

    int total = 0;

    while (!pq.empty())
    {
        planet cur = pq.top();
        pq.pop();

        // cout << cur.from << " " << cur.to << " " << cur.dist << endl;

        int a = findParents(cur.from);
        int b = findParents(cur.to);

        if (a == b)
        {
            continue;
        }
        else if (a < b)
        {
            galaxy[b] = a;
            total += cur.dist;
        }
        else
        {
            galaxy[a] = b;
            total += cur.dist;
        }
    }

    cout << total << endl;
}