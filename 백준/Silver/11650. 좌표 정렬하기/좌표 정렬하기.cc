#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y) {}
    p() {}

    bool operator<(const p temp) const
    {
        if (temp.x == x)
        {
            return y < temp.y;
        }
        return x < temp.x;
    }
};

int N;
vector<p> v;

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        v.push_back({x, y});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        cout << v[i].x << " " << v[i].y << "\n";
    }
}