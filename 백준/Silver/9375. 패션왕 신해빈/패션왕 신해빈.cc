#include <iostream>
#include <map>

using namespace std;

int N;

int main()
{
    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++)
    {
        cin >> N;

        map<string, int> s;
        map<string, int>::iterator iter;

        for (int i = 0; i < N; i++)
        {
            string name;
            string kind;
            cin >> name >> kind;

            if (s.find(kind) == s.end())
            {
                s.insert(pair<string, int>(kind, 1));
            }
            else
            {
                s[kind] += 1;
            }
        }

        int answer = 1;

        for (auto k : s)
        {
            answer *= (k.second + 1);
        }
        answer -= 1;

        cout << answer << "\n";
    }
}