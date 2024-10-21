#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO();

    while (1)
    {
        int x, n;
        cin >> x >> n;

        if (cin.eof())
        {
            break;
        }

        x *= 10000000;

        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            int l;
            cin >> l;

            v.push_back(l);
        }

        if (n < 2)
        {
            cout << "danger" << "\n";
            continue;
        }

        sort(v.begin(), v.end());

        int left = 0;
        int right = n - 1;
        bool found = false;

        while (left < right)
        {
            if (v[left] + v[right] == x)
            {
                cout << "yes " << v[left] << " " << v[right] << "\n";
                found = true;
                break;
            }

            if (v[left] + v[right] < x)
            {
                left += 1;
            }
            else
            {
                right -= 1;
            }
        }

        if (!found)
        {
            cout << "danger" << "\n";
        }
    }
}