#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> alphabet;
    alphabet.resize(27, 0);

    string sen;
    cin >> sen;

    for (int i = 0; i < sen.length(); i++)
    {
        if (sen[i] - 'A' >= 26)
        {
            alphabet[sen[i] - 'a'] += 1;
        }
        else
        {
            alphabet[sen[i] - 'A'] += 1;
        }
    }

    int max_value = *max_element(alphabet.begin(), alphabet.end());

    int cnt = 0;
    char idx;

    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] == max_value)
        {
            idx = i + 'A';
            cnt += 1;
        }
    }

    if (cnt == 1)
    {
        cout << idx << endl;
    }
    else
    {
        cout << "?" << endl;
    }
}