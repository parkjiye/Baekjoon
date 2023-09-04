#include <iostream>
#include <set>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int course[100005];

int findbuilding(int idx)
{
    if (idx == course[idx])
    {
        return idx;
    }
    else
    {
        return course[idx] = findbuilding(course[idx]);
    }
}

int main()
{
    FASTIO();

    int N, M;
    cin >> N >> M;

    for (int i = 0; i <= N; i++)
    {
        course[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        a = findbuilding(a);
        b = findbuilding(b);

        if (a < b)
        {
            course[b] = a;
        }
        else
        {
            course[a] = b;
        }
    }

    int ans = 0;

    int s, d;
    cin >> s;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> d;
        if (findbuilding(s) != findbuilding(d))
        {
            ans += 1;
        }

        s = d;
    }

    cout << ans << endl;
}