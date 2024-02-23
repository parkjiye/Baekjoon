#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int ans[1000005];
bool isCard[1000005];
vector<int> v;

int main()
{
    FASTIO();
    memset(ans, 0, sizeof(ans));
    memset(isCard, 0, sizeof(isCard));

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
        isCard[x] = true;
    }

    // sort(v.begin(), v.end());
    int max_num = *max_element(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 2; j * v[i] <= max_num; j++)
        {
            if (isCard[j * v[i]])
            {
                ans[v[i]] += 1;
                ans[j * v[i]] -= 1;
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << ans[v[i]] << " ";
    }
}