#include <iostream>
#include <set>
#include <queue>
using namespace std;

int main()
{
    set<string> s;
    priority_queue<string, vector<string>, greater<string>> pq;
    int d;
    int b;
    cin >> d >> b;

    int answer = 0;

    for (int i = 0; i < d; i++)
    {
        string name;
        cin >> name;
        s.insert(name);
    }

    for (int j = 0; j < b; j++)
    {
        string name;
        cin >> name;

        if (s.find(name) != s.end())
        {
            answer += 1;
            pq.push(name);
        }
    }

    cout << answer << endl;
    for (int i = 0; i < answer; i++)
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}