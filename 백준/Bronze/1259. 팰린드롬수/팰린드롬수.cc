#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    while (1)
    {
        string sentence;
        cin >> sentence;

        bool flag = false;

        if (sentence.compare("0") == 0)
            break;

        for (int i = 0; i < sentence.length() / 2; i++)
        {
            if (sentence[i] == sentence[sentence.length() - 1 -i]) {
                continue;
            }
            else
            {
                flag = true;
                cout << "no" << endl;
                break;
            }
            
        }
        if(!flag) cout << "yes" << endl;
    }
}