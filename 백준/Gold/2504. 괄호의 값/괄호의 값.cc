#include <iostream>
#include <stack>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO();
    string s;
    stack<string> st;

    cin >> s;
    int answer = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char cur = s[i];

        if (cur == '(' || cur == '[')
        {
            string tmp;
            tmp += cur;
            st.push(tmp);
        }
        else if (cur == ')')
        {

            int num = 0;
            bool found = false;

            while (!st.empty())
            {
                if (st.top().compare("(") == 0)
                {
                    found = true;
                    st.pop();
                    if (num == 0)
                    {
                        st.push("2");
                    }
                    else
                    {
                        st.push(to_string(2 * num));
                    }
                    break;
                }
                else if (st.top().compare("[") == 0 || st.top().compare("]") == 0)
                {
                    break;
                }
                else
                {
                    string tmp = st.top();
                    int nxt = stoi(tmp);
                    st.pop();
                    num += nxt;
                }
            }

            if (!found)
            {
                cout << 0 << "\n";
                return 0;
            }
        }
        else
        {

            int num = 0;
            bool found = false;

            while (!st.empty())
            {
                if (st.top().compare("[") == 0)
                {
                    st.pop();
                    found = true;

                    if (num == 0)
                    {
                        st.push("3");
                    }
                    else
                    {
                        st.push(to_string(3 * num));
                    }
                    break;
                }
                else if (st.top().compare("(") == 0 || st.top().compare(")") == 0)
                {
                    break;
                }
                else
                {
                    string tmp = st.top();
                    int nxt = stoi(tmp);
                    st.pop();
                    num += nxt;
                }
            }

            if (!found)
            {
                cout << 0 << "\n";
                return 0;
            }
        }
    }

    while (!st.empty())
    {
        string tmp = st.top();

        if (st.top().compare("(") == 0 || st.top().compare(")") == 0 || st.top().compare("[") == 0 || st.top().compare("]") == 0)
        {
            cout << "0" << "\n";
            return 0;
        }
        else
        {
            answer += stoi(tmp);
        }

        st.pop();
    }

    cout << answer << "\n";
}