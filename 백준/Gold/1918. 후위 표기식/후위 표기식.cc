#include <iostream>
#include <stack>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO();

    string sen;
    cin >> sen;

    stack<char> s;

    for (int i = 0; i < sen.length(); i++)
    {
        if (sen[i] >= 'A' && sen[i] <= 'Z')
        {
            cout << sen[i];
        }
        else
        {
            if (sen[i] == '+' || sen[i] == '-')
            {
                while (!s.empty())
                {
                    if (s.top() != '(')
                    {
                        cout << s.top();
                        s.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                s.push(sen[i]);
            }
            else if (sen[i] == '*' || sen[i] == '/')
            {
                while (!s.empty())
                {
                    if (s.top() == '*' || s.top() == '/')
                    {
                        cout << s.top();
                        s.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                s.push(sen[i]);
            }
            else if (sen[i] == '(')
            {
                s.push(sen[i]);
            }
            else if (sen[i] == ')')
            {
                while (s.top() != '(')
                {
                    cout << s.top();
                    s.pop();
                }
                s.pop();
            }
        }
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    cout << endl;

    return 0;
}