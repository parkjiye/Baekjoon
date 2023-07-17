#include <iostream>
#include <vector>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int get_distance(string a, string b)
{
    int dist = 0;

    for (int i = 0; i < 4; i++)
    {
        if (a[i] != b[i])
        {
            dist += 1;
        }
    }

    return dist;
}

int main()
{
    FASTIO();

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int x;
        cin >> x;

        vector<string> v;

        for (int p = 0; p < x; p++)
        {
            string sen;
            cin >> sen;
            v.push_back(sen);
        }

        if (x > 32)
        {
            cout << 0 << "\n";
        }
        else
        {
            int min_dist = 1000;

            for (int i = 0; i < x - 2; i++)
            {
                for (int j = i + 1; j < x - 1; j++)
                {
                    for (int k = j + 1; k < x; k++)
                    {
                        min_dist = min(min_dist, get_distance(v[i], v[j]) + get_distance(v[i], v[k]) + get_distance(v[j], v[k]));
                    }
                }
            }

            cout << min_dist << "\n";
        }
    }
}