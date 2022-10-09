#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int count;
    cin>>count;
    int check=0;
    int number=0;
    stack<char> stk;

    string people;
    cin>>people;

    int man=0;
    int woman=0;
    char now;

    bool waiting=false;

    for(int i=0;i<people.size();i++)
    {
        if(people[i]=='M')
        {
            check=abs((man+1)-woman);
            if(count>=check)
            {
                man++;
            }
            else
            {
                if(!waiting)
                {
                    now='M';
                    waiting=true;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            check=abs(man-(woman+1));
            if(count>=check)
            {
                woman++;
            }
            else
            {
                if(!waiting)
                {
                    now='W';
                    waiting=true;
                }
                else
                {
                    break;
                }
            }
        }

        if(waiting)
        {
            if(now=='M')
            {
                check=abs((man+1)-woman);
                if(count>=check)
                {
                    man++;
                    waiting=false;
                }
            }
            else
            {
                check=abs(man-(woman+1));
                if(count>=check)
                {
                    woman++;
                    waiting=false;
                }
            }
        }
    }

    number=man+woman;

    cout<<number<<endl;
}