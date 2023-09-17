#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;

int myMap[1000005];

int findParents(int idx)
{
    if (idx == myMap[idx])
    {
        return idx;
    }
    else
    {
        return myMap[idx] = findParents(myMap[idx]);
    }
}

int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        myMap[i] = i;
    }

    vector<pair<int, int>> tmp;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        tmp.push_back({a, b});
    }

    sort(tmp.begin(), tmp.end());

    for (int i = 0; i < tmp.size(); i++)
    {
        int a = tmp[i].first;
        int b = tmp[i].second;

        for (int i = a; i < b; i++)
        {
            int a = findParents(i);
            int b = findParents(i + 1);

            if (a != b)
            {
                myMap[b] = a;
            }
        }
    }

    set<int> s;

    for (int i = 1; i <= N; i++)
    {
        s.insert(myMap[i]);
    }

    cout << s.size() << endl;
}