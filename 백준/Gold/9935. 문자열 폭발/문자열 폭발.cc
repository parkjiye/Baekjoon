#include <iostream>
#include <stack>
#include <queue>

using namespace std;

string sen;
string word;

stack<char> temp;
stack<char> origin;

void fill()
{
    while (!origin.empty())
    {
        origin.pop();
    }

    for (int i = 0; i < word.length(); i++)
    {
        origin.push(word[i]);
    }
}

int main()
{
    cin >> sen;
    cin >> word;

    fill();

    for (int i = 0; i < sen.length(); i++)
    {
        temp.push(sen[i]);

        if (temp.top() == origin.top())
        {
            string tmp;

            while (1)
            {
                tmp += temp.top();

                temp.pop();
                origin.pop();

                if (origin.empty())
                {
                    break;
                }

                if (temp.empty())
                {
                    for (int j = tmp.length() - 1; j >= 0; j--)
                    {
                        temp.push(tmp[j]);
                    }
                    break;
                }

                if (origin.top() != temp.top())
                {
                    for (int j = tmp.length() - 1; j >= 0; j--)
                    {
                        temp.push(tmp[j]);
                    }
                    break;
                }
            }

            fill();
        }
    }

    if (temp.size() == 0)
    {
        cout << "FRULA" << endl;
        return 0;
    }

    deque<char> answer;

    while (temp.size())
    {
        answer.push_front(temp.top());
        temp.pop();
    }

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
    }
    cout << endl;

    return 0;
}