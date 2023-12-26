#include <iostream>

using namespace std;

int N;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        int answer = 0;
        int cnt = 0;

        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == 'O')
            {
                cnt += 1;
                answer += cnt;
            }
            else
            {
                cnt = 0;
            }
        }
        cout << answer << "\n";
    }
}