#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, S, R;
    cin >> N >> S >> R;

    bool possible[13];

    for (int i = 0; i <= N; i++)
    {
        possible[i] = true;
    }

    for (int i = 0; i < S; i++)
    {
        int x;
        cin >> x;

        possible[x] = false;
    }

    vector<int> angels;

    for (int i = 0; i < R; i++)
    {
        int x;
        cin >> x;

        if (possible[x] == false)
        {
            possible[x] = true;
            continue;
        }

        angels.push_back(x);
    }

    for (int i = 0; i < angels.size(); i++)
    {
        int x = angels[i];
        if (x == 1 && possible[x + 1] == false)
        {
            possible[x + 1] = true;
        }
        else if (x == N && possible[x - 1] == false)
        {
            possible[x - 1] = true;
        }
        else
        {
            if (possible[x - 1] == false)
            {
                possible[x - 1] = true;
                continue;
            }

            if (possible[x + 1] == false)
            {
                possible[x + 1] = true;
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= N; i++)
    {
        if (!possible[i])
        {
            ans += 1;
        }
    }

    cout << ans << endl;

    return 0;
}