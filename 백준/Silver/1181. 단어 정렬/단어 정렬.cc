#include <iostream>
#include <queue>
#include <set>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct word
{
    string s;
    int length;

    word(string s, int length) : s(s), length(length) {}
    word() {}

    bool operator<(const word temp) const
    {
        if (length == temp.length)
        {
            return s < temp.s;
        }
        return length < temp.length;
    }
};

set<word> pq;

int main()
{
    FASTIO();
    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string w;
        cin >> w;

        pq.insert(word(w, w.length()));
    }

    for (auto it = pq.begin(); it != pq.end(); it++)
    {
        cout << it->s << "\n";
    }
}