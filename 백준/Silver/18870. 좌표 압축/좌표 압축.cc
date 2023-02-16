#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int num;
    cin >> num;

    vector<int> arr;
    map<int, int, less<int>> m;

    for (int i = 0; i < num; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
        m.insert({a, 0});
    }

    int cnt = 0;

    for (auto &at : m)
    {
        at.second = cnt++;
    }

    for (int i = 0; i < num; i++)
    {
        cout << m.find(arr[i])->second << " ";
    }

    cout << endl;
    return 0;
}