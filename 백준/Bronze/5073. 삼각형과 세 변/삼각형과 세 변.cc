#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int x, y, z;
    while (1)
    {
        cin >> x >> y >> z;

        vector<int> v;

        if (x == 0 && y == 0 && z == 0)
        {
            break;
        }
        else
        {
            v.push_back(x);
            v.push_back(y);
            v.push_back(z);

            sort(v.begin(), v.end());

            if (v[0] + v[1] <= v[2])
            {
                cout << "Invalid" << endl;
                continue;
            }
            else if (v[0] == v[1] && v[1] == v[2] && v[0] == v[2])
            {
                cout << "Equilateral" << endl;
                continue;
            }
            else if (v[0] == v[1] || v[1] == v[2] || v[0] == v[2])
            {
                cout << "Isosceles" << endl;
                continue;
            }
            else
            {
                cout << "Scalene" << endl;
                continue;
            }
        }
    }

    return 0;
}