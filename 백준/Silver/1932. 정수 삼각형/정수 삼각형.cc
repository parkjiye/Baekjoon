#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<int> v[500];

int main()
{
    FASTIO();

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (j == 0)
                v[i][j] += v[i - 1][j];
            else if (j == v[i].size() - 1)
                v[i][j] += v[i - 1][j - 1];
            else
                v[i][j] += max(v[i - 1][j - 1], v[i - 1][j]);
        }
    }

    cout << *max_element(v[N - 1].begin(), v[N - 1].end()) << endl;
}