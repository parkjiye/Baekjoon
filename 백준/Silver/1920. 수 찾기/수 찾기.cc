#include <iostream>
#include <map>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO();
    int N;
    cin >> N;

    map<int, bool> m;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        m.insert({x, true});
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;

        if (m[x] == true)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}