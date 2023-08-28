#include <iostream>
#include <vector>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n, k;
vector<int> v;

long long int myMap[10005] = {
    0,
};

int main()
{
    FASTIO();
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);
    }

    myMap[0] = 1;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int temp = j - v[i];

            if (temp < 0)
            {
                continue;
            }
            else
            {
                myMap[j] += myMap[temp];
            }
        }
    }

    cout << myMap[k] << endl;
}