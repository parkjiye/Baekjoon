#include <iostream>
#include <algorithm>
#include <vector>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct p
{
    int age;
    int order;
    string name;

    p(int age, int order, string name) : age(age), order(order), name(name) {}
    p() {}

    bool const operator<(const p temp) const
    {
        if (age == temp.age)
        {
            return order < temp.order;
        }
        return age < temp.age;
    }
};

int main()
{
    FASTIO();
    int N;
    cin >> N;

    vector<p> v;

    for (int i = 1; i <= N; i++)
    {
        int x;
        string y;
        cin >> x >> y;

        v.push_back(p(x, i, y));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        cout << v[i].age << " " << v[i].name << "\n";
    }
}