#include <iostream>

using namespace std;

int main()
{
    string sen;
    getline(cin, sen);

    int answer = 0;

    for (int i = 1; i < sen.length(); i++)
    {
        if (sen[i - 1] != ' ' && sen[i] == ' ')
        {
            answer += 1;
        }
    }

    if (sen[sen.length() - 1] != ' ')
    {
        answer += 1;
    }

    cout << answer << endl;
}