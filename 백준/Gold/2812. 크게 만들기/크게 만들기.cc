#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, K;
string s;

struct p
{
    int cnt;
    int num;

    p() {}
    p(int cnt, int num) : cnt(cnt), num(num) {}
};

vector<p> v;
stack<int> stk;

int main()
{
    FASTIO();
    cin >> N >> K;
    cin >> s;

    int digit = N - K;

    for (int i = 0; i < s.length(); i++)
    {
        string tmp = s.substr(i, 1);
        v.push_back(p(digit, stoi(tmp)));

        if (digit >= s.length() - i)
        {
            digit -= 1;
        }
    }

    string answer;
    int cur_digit = N - K;

    for (int i = 0; i < v.size(); i++)
    {
        if (stk.empty())
        {
            stk.push(v[i].num);
        }
        else
        {
            while (!stk.empty() && stk.top() < v[i].num && v[i].cnt >= cur_digit - stk.size() + 1)
            {
                stk.pop();
            }
            if (stk.size() < cur_digit)
            {
                stk.push(v[i].num);
            }
        }
    }

    vector<int> tmp;

    while (!stk.empty())
    {
        int cur = stk.top();
        stk.pop();

        tmp.push_back(cur);
    }

    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        answer += to_string(tmp[i]);
    }

    cout << answer << "\n";
}