#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
vector<int> v;

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int left = 0;
    int right = N - 1;
    long sum = 2000000005;
    pair<int, int> ans;

    while (left < right)
    {
        if (abs(v[left] + v[right]) < sum)
        {
            sum = abs(v[left] + v[right]);
            ans.first = v[left];
            ans.second = v[right];
        }

        if (abs(v[left + 1] + v[right]) > abs(v[left] + v[right - 1]))
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    cout << ans.first << " " << ans.second << "\n";
}