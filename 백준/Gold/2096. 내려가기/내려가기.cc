#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int N;
vector<int> v(3, 0);
vector<int> m(3, 0);

int dx[3] = {1, 1, 1};
int dy[3] = {0, 1, -1};

int maximum;
int minimum;

int main()
{
    FASTIO();

    cin >> N;
    vector<int> answer;

    for (int i = 0; i < N; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        if (i == 0)
        {
            v[0] = x;
            v[1] = y;
            v[2] = z;

            m[0] = x;
            m[1] = y;
            m[2] = z;
        }
        else
        {
            int temp1, temp2, temp3;
            temp1 = x + max(v[0], v[1]);
            temp2 = y + max(v[0], max(v[1], v[2]));
            temp3 = z + max(v[1], v[2]);

            v[0] = temp1;
            v[1] = temp2;
            v[2] = temp3;

            temp1 = x + min(m[0], m[1]);
            temp2 = y + min(m[0], min(m[1], m[2]));
            temp3 = z + min(m[1], m[2]);

            m[0] = temp1;
            m[1] = temp2;
            m[2] = temp3;
        }
    }

    cout << max(v[0], max(v[1], v[2])) << " " << min(m[0], min(m[1], m[2])) << endl;
}