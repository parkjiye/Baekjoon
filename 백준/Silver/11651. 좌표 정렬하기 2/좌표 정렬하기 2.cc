#include <iostream>
#include <algorithm>
#include <vector>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct p
{
    int x;
    int y;

    p() {}
    p(int x, int y) : x(x), y(y) {}

    bool const operator<(p tmp) const
    {
        if (y == tmp.y)
        {
            return x < tmp.x;
        }
        return y < tmp.y;
    }
};

vector<p> v;

int main()
{
    FASTIO();
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        v.push_back(p(x, y));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        cout << v[i].x << " " << v[i].y << "\n";
    }
}