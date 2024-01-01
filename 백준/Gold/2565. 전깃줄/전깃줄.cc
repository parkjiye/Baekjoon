#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

struct p
{
    int left;
    int right;

    p(int left, int right) : left(left), right(right) {}
    p() {}

    bool const operator<(const p temp) const
    {
        return left < temp.left;
    }
};

vector<p> v;
int dp[505];

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        v.push_back(p(x, y));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 505; i++)
    {
        dp[i] = 1;
    }

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i].right > v[j].right)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (dp[i] > answer)
        {
            answer = dp[i];
        }
    }

    cout << N - answer << "\n";
}