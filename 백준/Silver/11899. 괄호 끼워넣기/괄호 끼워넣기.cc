#include <iostream>
#include <stack>

using namespace std;

int paren_check(const string& s)
{
    stack<char> stk;
    int check=0;

    for(char c : s)
    {
        if(c=='(')
        {
            stk.push(c);
        }
        else
        {

            if(stk.empty() || stk.top()=='(' && c!=')')
            {
                check++;
            }
            else
            {
                stk.pop();
            }

        }
    }
    
    if(stk.empty())
    {
        return check;    
    }
    else{
        while(!stk.empty())
        {
            check++;
            stk.pop();
        }
        return check;
    }
}

int main()
{

    string sentence;

    cin>>sentence;
    cout<<paren_check(sentence)<<endl;
}