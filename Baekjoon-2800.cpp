#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct paren_pos
{
    int start;
    int end;
};

vector<paren_pos> pos();

int paren_check(const string& s)
{
    int paren=0;
    stack<char> stk;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {

            stk.push(s[i]);
            paren++;
        }
        else
        {
            if(stk.top()=='('&& s[i]==')')
            {
                stk.pop();
            }
        }
    }
    
    if(stk.empty())
    {
        return paren;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string sentence;
    cin>>sentence;

    

    cout<<paren_check(sentence)<<endl;

    
}