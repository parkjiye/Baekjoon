#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test_cases;
    cin >> test_cases;
    set<int> s;
    set<int> allSet = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    for (int test_case = 0; test_case < test_cases; test_case++)
    {
        string sen;
        cin >> sen;
        int num;

        if (sen == "add")
        {
            cin >> num;
            s.insert(num);
        }
        else if (sen == "remove")
        {
            cin >> num;
            s.erase(num);
        }
        else if (sen == "check")
        {
            cin >> num;
            if (s.find(num) != s.end())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (sen == "toggle")
        {
            cin >> num;
            if (s.find(num) != s.end())
                s.erase(num);
            else
                s.insert(num);
        }
        else if (sen == "all")
        {
            s = allSet;
        }
        else
        {
            s.clear();
        }
    }
}