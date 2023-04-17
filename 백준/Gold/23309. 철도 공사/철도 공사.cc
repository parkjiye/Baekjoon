#include <iostream>
#include <vector>
#include <unordered_map>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;

struct station
{
    int prev = 0;
    int next = 0;

    station() {}
    station(int prev, int next) : prev(prev), next(next) {}
};

station stations[1000005];

int main()
{
    FASTIO();

    cin >> N >> M;

    int start, end;
    vector<int> tmp;
    int x;

    if (N == 1)
    {
        cin >> x;
        stations[x] = station();
    }
    else
    {
        for (int i = 0; i < N; ++i)
        {
            cin >> x;
            tmp.push_back(x);

            if (i < N - 1)
            {
                stations[x].prev = tmp[i - 1];
                stations[tmp[i - 1]].next = x;
            }
            else
            {
                stations[x].prev = tmp[i - 1];
                stations[tmp[i - 1]].next = x;
                stations[x].next = tmp[0];
                stations[tmp[0]].prev = tmp[N - 1];
            }
        }
    }

    for (int m = 0; m < M; m++)
    {
        string sen;
        cin >> sen;

        int i, j;

        if (sen == "BN")
        {
            cin >> i >> j;

            int next = stations[i].next;

            if (next == 0)
            {
                cout << i << "\n";

                stations[i] = station(j, j);
                stations[j] = station(i, i);
            }
            else
            {
                cout << next << "\n";

                stations[i].next = j;
                stations[next].prev = j;
                stations[j] = station(i, next);
            }
        }
        else if (sen == "BP")
        {
            cin >> i >> j;

            int prev = stations[i].prev;

            if (prev == 0)
            {
                cout << i << "\n";

                stations[i] = station(j, j);
                stations[j] = station(i, i);
            }
            else
            {
                cout << prev << "\n";

                stations[i].prev = j;
                stations[prev].next = j;
                stations[j] = station(prev, i);
            }
        }
        else if (sen == "CN")
        {
            cin >> i;

            int next = stations[i].next;
            int nnext = stations[next].next;

            cout << next << "\n";
            stations[i].next = nnext;
            stations[nnext].prev = i;

            stations[next] = {};
        }
        else
        {
            cin >> i;

            int prev = stations[i].prev;
            int pprev = stations[prev].prev;

            cout << prev << "\n";
            stations[i].prev = pprev;
            stations[pprev].next = i;

            stations[prev] = {};
        }
    }

    return 0;
}