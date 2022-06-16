#include <iostream>
#include <stack>

using namespace std;

string paren_check(const string& s)
{
    stack<char> stk;
    for(char c : s)
    {
        if(c=='('||c=='{'||c=='[')
        {
            stk.push(c);
        }
        else
        {

            if(stk.empty() || stk.top()=='(' && c!=')' ||
                stk.top()=='{' && c!='}' ||
                stk.top()=='[' && c!=']')
                {
                    return "NO";
                }

            stk.pop();
        }
    }
    
    if(stk.empty())
    {
        return "YES";
    }
    else{
        return "NO";
    }
}

int main()
{
    int count;
    cin>>count;

    string sentence;

    for(int i=0;i<count;i++)
    {
        cin>>sentence;
        cout<<paren_check(sentence)<<endl;
    }
}