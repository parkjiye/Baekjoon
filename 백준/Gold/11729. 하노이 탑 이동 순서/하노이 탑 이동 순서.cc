#include <iostream>
#include <vector>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
vector<pair<int, int>> v;

void move(int n, int start, int to)
{
    v.push_back({start, to});
}

void hanoi(int n, int start, int to, int via)
{
    if (n == 1)
    {
        move(1, start, to);
    }
    else
    {
        hanoi(n - 1, start, via, to);
        move(n, start, to);
        hanoi(n - 1, via, to, start);
    }
}

int main()
{
    FASTIO();
    cin >> N;

    hanoi(N, 1, 3, 2);

    cout << v.size() << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}