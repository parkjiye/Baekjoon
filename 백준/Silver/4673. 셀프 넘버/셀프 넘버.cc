#include <iostream>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false);

using namespace std;

int getNextNum(int num)
{
    string s = to_string(num);
    int sum = num;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        string tmp;
        tmp += c;
        sum += stoi(tmp);
    }

    return sum;
}

int main()
{
    FASTIO();

    bool isSelf[10005] = {
        0,
    };

    for (int i = 1; i <= 10000; i++)
    {
        if (!isSelf[i])
        {
            int nxt = getNextNum(i);

            while (!isSelf[nxt] && nxt <= 10000)
            {
                isSelf[nxt] = true;
                nxt = getNextNum(nxt);
            }
        }
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (!isSelf[i])
        {
            cout << i << "\n";
        }
    }
}