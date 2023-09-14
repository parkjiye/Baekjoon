#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int galaxy[100005];
long long int planet[100005];

int findParents(int idx)
{
    if (galaxy[idx] == idx)
    {
        return idx;
    }
    else
    {
        return galaxy[idx] = findParents(galaxy[idx]);
    }
}

int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        long long int x;
        cin >> x;

        planet[i] = x;
        galaxy[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        a = findParents(a);
        b = findParents(b);

        if (a < b)
        {
            galaxy[b] = a;
            planet[a] += planet[b];
            planet[b] = 0;

            cout << planet[a] << "\n";
        }
        else if (a == b)
        {
            cout << planet[a] << "\n";
        }
        else
        {
            galaxy[a] = b;
            planet[b] += planet[a];
            planet[a] = 0;
            cout << planet[b] << "\n";
        }
    }
}