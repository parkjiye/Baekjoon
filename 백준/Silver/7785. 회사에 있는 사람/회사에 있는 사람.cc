#include <iostream>
#include <map>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO();
    int N;
    cin >> N;
    map<string, bool, greater<string>> m;

    for (int i = 0; i < N; i++)
    {
        string name, status;
        cin >> name >> status;

        if (status == "enter")
        {
            if (m.find(name) != m.end())
            {
                m[name] = true;
                        }
            else
            {
                m.insert({name, true});
            }
        }
        else
        {
            m[name] = false;
        }
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second)
        {
            cout << it->first << "\n";
        }
    }
}