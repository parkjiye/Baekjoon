#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct p
{
    int s;
    int e;
};

p make_p(int a, int b)
{
    p temp;
    temp.s = a;
    temp.e = b;
    return temp;
}

bool cmp(p n1, p n2)
{
    if (n1.e == n2.e)
        return n1.s < n2.s;

    return n1.e < n2.e;
}

int main()
{
    int num;
    cin >> num;

    vector<p> pq;

    for (int i = 0; i < num; i++)
    {
        int a, b;
        cin >> a >> b;
        pq.push_back(make_p(a, b));
    }

    sort(pq.begin(), pq.end(), cmp);

    int answer = 1;

    p cur = pq[0];
    for (int i = 1; i < num; i++)
    {
        if (cur.e <= pq[i].s)
        {
            answer += 1;
            cur = pq[i];
        }
    }

    cout << answer << endl;
}