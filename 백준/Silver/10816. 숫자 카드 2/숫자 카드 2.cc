#include <iostream>
#include <vector>
#include <map>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

map<int, int> m;
int N, M;

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        if (m.find(x) == m.end())
        {
            m.insert({x, 1});
        }
        else
        {
            m[x] += 1;
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;

        cout << m[x] << " ";
    }
    cout << "\n";
}