#include <iostream>

using namespace std;

int main()
{
    while (1)
    {
        string s;
        getline(cin, s);

        if (s == "#")
        {
            return 0;
        }

        int cnt = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                cnt += 1;
            }
        }

        cout << cnt << "\n";
    }
}