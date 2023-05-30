#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N;
    cin >> N;

    set<int> s;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        s.insert(x);
    }

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
    return 0;
}