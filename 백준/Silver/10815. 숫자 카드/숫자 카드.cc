#include <iostream>
#include <set>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

set<int> card;

int main()
{
    FASTIO();
    int N, M;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        card.insert(x);
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;

        if (card.find(x) != card.end())
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
}
