#include <iostream>
#include <vector>
#include <set>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, K;
vector<string> v;
set<char> s;
vector<char> c;
char path[30];
bool visited[30];
int answer = 0;

void backtracking(int idx, int left)
{
    if (idx == left)
    {
        s.clear();
        s.insert('a');
        s.insert('c');
        s.insert('i');
        s.insert('n');
        s.insert('t');

        for (int i = 0; i < left; i++)
        {
            s.insert(c[path[i]]);
        }

        int cnt = 0;

        for (int i = 0; i < N; i++)
        {
            int tmp = 0;
            for (int j = 0; j < v[i].length(); j++)
            {
                if (s.find(v[i][j]) == s.end())
                {
                    break;
                }
                else
                {
                    tmp += 1;
                }
            }
            if (tmp == v[i].length())
            {
                cnt += 1;
            }
        }

        if (cnt > answer)
        {
            answer = cnt;
        }

        return;
    }
    else
    {
        for (int i = 0; i < c.size(); i++)
        {
            if (idx == 0 || path[idx - 1] < i)
            {
                path[idx] = i;
                backtracking(idx + 1, left);
            }
        }
    }
}

int main()
{
    FASTIO();
    cin >> N >> K;

    s.insert('a');
    s.insert('c');
    s.insert('i');
    s.insert('n');
    s.insert('t');
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        str = str.substr(4, str.length() - 8);
        v.push_back(str);

        for (int j = 0; j < str.length(); j++)
        {
            s.insert(str[j]);
        }
    }

    if (K < 5)
    {
        cout << 0 << "\n";
    }
    else if (K == 26)
    {
        cout << N << "\n";
    }
    else
    {
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (*it != 'a' && *it != 'c' && *it != 'i' && *it != 'n' && *it != 't')
            {
                c.push_back(*it);
            }
        }

        if (K - 5 >= c.size())
        {
            cout << N << "\n";
        }
        else
        {
            backtracking(0, K - 5);
            cout << answer << "\n";
        }
    }
}