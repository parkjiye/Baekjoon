#include <iostream>
#include <queue>
#include <algorithm>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct homework
{
    int d;
    int w;

    homework() {}
    homework(int d, int w) : d(d), w(w) {}

    bool const operator<(homework temp) const
    {
        if (w == temp.w)
        {
            return d < temp.d;
        }
        return w < temp.w;
    }
};

struct cmp
{
    bool operator()(homework a, homework b)
    {
        if (a.d == b.d)
        {
            return a.w < b.w;
        }
        return a.d < b.d;
    }
};

priority_queue<homework> pq;
priority_queue<homework, vector<homework>, cmp> v;
int N;

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int d, w;
        cin >> d >> w;

        v.push(homework(d, w));
    }

    int day = v.top().d;
    int answer = 0;

    for (int d = day; d > 0; d--)
    {
        while (!v.empty())
        {
            if (v.top().d == d)
            {
                pq.push(v.top());
                v.pop();
            }
            else
            {
                break;
            }
        }

        if (!pq.empty())
        {
            // cout << d << " " << pq.top().w << "\n";
            answer += pq.top().w;
            pq.pop();
        }
    }

    cout << answer << "\n";
}