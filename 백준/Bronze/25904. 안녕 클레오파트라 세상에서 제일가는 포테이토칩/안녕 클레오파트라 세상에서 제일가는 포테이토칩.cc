#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int x;

    cin >> n >> x;

    vector<int> line;

    for (int i = 0; i < n; i++)
    {
        int high;
        cin >> high;
        line.push_back(high);
    }

    int now = 0;

    while (1)
    {
        if (now == n)
            now = 0;
        if (x > line[now])
            break;
        else
        {
            x += 1;
            now += 1;
        }
    }

    cout << now + 1 << endl;
}