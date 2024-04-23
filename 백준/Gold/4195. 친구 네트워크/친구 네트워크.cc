#include <iostream>
#include <map>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

map<string, int> friends;
int parent[200001];
map<int, int> cnt;

int findParents(int idx)
{
    if (idx == parent[idx])
    {
        return idx;
    }
    else
    {
        return parent[idx] = findParents(parent[idx]);
    }
}

int main()
{
    FASTIO();
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        friends.clear();
        cnt.clear();

        int F;
        cin >> F;

        for (int i = 1; i <= F * 2; i++)
        {
            parent[i] = i;
            cnt.insert({i, 1});
        }

        int f = 1;

        for (int i = 0; i < F; i++)
        {
            string a, b;
            cin >> a >> b;

            auto a_it = friends.find(a);
            auto b_it = friends.find(b);

            if (a_it == friends.end() && b_it == friends.end())
            {
                friends.insert({a, f});
                f += 1;
                friends.insert({b, f});
                f += 1;
            }
            else if (a_it == friends.end() && b_it != friends.end())
            {
                friends.insert({a, f});
                f += 1;
            }
            else if (a_it != friends.end() && b_it == friends.end())
            {
                friends.insert({b, f});
                f += 1;
            }

            int a_idx = findParents(friends[a]);
            int b_idx = findParents(friends[b]);

            if (a_idx == b_idx)
            {
                cout << cnt[a_idx] << "\n";
            }
            else if (a_idx < b_idx)
            {
                parent[b_idx] = a_idx;
                cnt[a_idx] += cnt[b_idx];
                cout << cnt[a_idx] << "\n";
            }
            else
            {
                parent[a_idx] = b_idx;
                cnt[b_idx] += cnt[a_idx];
                cout << cnt[b_idx] << "\n";
            }

        }
    }
}