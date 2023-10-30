#include <iostream>
#include <map>
#include <math.h>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct word
{
    int cnt;
    char x;

    word() {}
    word(int cnt, char x) : cnt(cnt), x(x) {}

    bool operator<(const word temp) const
    {
        return cnt < temp.cnt;
    }
};

int main()
{
    FASTIO();

    int N;
    cin >> N;
    map<char, int> m;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = s.size() - 1; j >= 0; j--)
        {
            if (m.find(s[j]) != m.end())
            {
                m[s[j]] += pow(10, (s.size() - j - 1));
            }
            else
            {
                m.insert({s[j], pow(10, (s.size() - j - 1))});
            }
        }
    }

    priority_queue<word> pq;

    for (auto it = m.begin(); it != m.end(); it++)
    {
        pq.push(word(it->second, it->first));
        // cout << it->first << " " << it->second << endl;
    }

    int num = 9;
    int answer = 0;

    while (!pq.empty())
    {
        word cur = pq.top();
        pq.pop();

        answer += num * cur.cnt;
        num--;
    }

    cout << answer << "\n";
}