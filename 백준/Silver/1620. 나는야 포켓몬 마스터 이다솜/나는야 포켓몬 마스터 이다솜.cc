#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    map<string, string> m;

    for (int i = 1; i <= N; i++)
    {
        string sen;
        cin >> sen;
        m.insert(pair<string, string>(sen, to_string(i)));
        m.insert(pair<string, string>(to_string(i), sen));
    }

    for (int i = 0; i < M; i++)
    {
        string sen;
        cin >> sen;

        auto it = m.find(sen);

        if (it->first == sen)
        {
            cout << it->second << "\n";
        }
        if (it->second == sen)
        {
            cout << it->first << "\n";
        }
    }
    return 0;
}